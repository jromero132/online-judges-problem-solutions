// Problem name: Till I Collapse
// Problem link: https://vjudge.net/problem/CodeForces-786C
// Submission link: https://vjudge.net/solution/13287885

#include <bits/stdc++.h>

#define MAX ((int)100001)
#define MID(a, b) (((a) + (b)) >> 1)
#define LEFT(x) ((x) << 1)
#define RIGHT(x) ((x) << 1 | 1)
#define endl '\n'

using namespace std;

struct node{
    int sum;
    node *left, *right;

    node(): left(NULL), right(NULL), sum(0){ }

    node(node *left, node *right, int sum) : left(left), right(right), sum(sum){ }
};

int n, color[ MAX ], Next[ MAX ];
node *tree[ MAX << 1 ];

void build(node *t, int left, int right){
    if(left + 1 == right)
        return;
    int middle = MID(left, right);
    t -> left = new node(NULL, NULL, 0);
    t -> right = new node(NULL, NULL, 0);
    build(t -> left, left, middle);
    build(t -> right, middle, right);
    t -> sum = (t -> left -> sum) + (t -> right -> sum);
}

void upgrade(node *prev, node *cur, int left, int right, int p, int v){
    if(left + 1 == right){
        cur -> sum = v;
        return;
    }
    int middle = MID(left, right);
    if(p < middle){
        cur -> left = new node(NULL, NULL, 0);
        upgrade(prev -> left, cur -> left, left, middle, p, v);
        cur -> right = prev -> right;
    }
    else{
        cur -> left = prev -> left;
        cur -> right = new node(NULL, NULL, 0);
        upgrade(prev -> right, cur -> right, middle, right, p, v);
    }
    cur -> sum = (cur -> left -> sum) + (cur -> right -> sum);
}

int query(node *t, int ileft, int iright, int left, int right){
    if(ileft >= left && iright <= right)
        return t -> sum;
    int imiddle = MID(ileft, iright), ans = 0;
    if(left < imiddle)
        ans += query(t -> left, ileft, imiddle, left, right);
    if(imiddle < right)
        ans += query(t -> right, imiddle, iright, left, right);
    return ans;
}

int limit(node *t, int left, int right, int k){
    if(k >= t -> sum)
        return right;
    if(left + 1 == right)
        return left;
    int middle = MID(left, right);
    if(k >= (t -> left -> sum))
        return limit(t -> right, middle, right, k - (t -> left -> sum));
    return limit(t -> left, left, middle, k);
}

int squads(int k){
    int ans = 0, p = 0;
    while(p != n)
        p = limit(tree[ p << 1 ], 0, n, k), ans++;
    return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    memset(Next, -1, sizeof(Next));

    int c;
    node *root, *aux;
    cin >> n;
    for(int i = 0 ; i < n ; i++)
        cin >> color[ i ];
    root = new node(NULL, NULL, 0);
    build(root, 0, n);
    tree[ LEFT(n) ] = root;
    for(int i = n ; i-- ; ){
        root = new node(NULL, NULL, 0);
        c = color[ i ];
        if(Next[ c ] == -1){
            aux = tree[ LEFT(i + 1) ];
            root -> left = aux -> left;
            root -> right = aux -> right;
            root -> sum = aux -> sum;
        }
        else
            upgrade(tree[ LEFT(i + 1) ], root, 0, n, Next[ c ], 0);
        tree[ RIGHT(i) ] = root;
        root = new node(NULL, NULL, 0);
        upgrade(tree[ RIGHT(i) ], root, 0, n, i, 1);
        tree[ LEFT(i) ] = root;
        Next[ c ] = i;
    }
    cout << squads(1);
    for(int k = 2 ; k <= n ; k++)
        cout << ' ' << squads(k);
    cout << endl;
	return 0;
}
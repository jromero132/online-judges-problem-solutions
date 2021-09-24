// Problem name: Destiny
// Problem link: https://vjudge.net/problem/CodeForces-840D
// Submission link: https://vjudge.net/solution/13326174

#include <bits/stdc++.h>

#define MAX ((int)300003)
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

    node(node *t) : left(t -> left), right(t -> right), sum(t -> sum){ }
};

int n;
node *tree[ MAX ];

void build(node *t, int left, int right){
    if(left + 1 == right)
        return;
    int middle = MID(left, right);
    t -> left = new node(NULL, NULL, 0);
    t -> right = new node(NULL, NULL, 0);
    build(t -> left, left, middle);
    build(t -> right, middle, right);
}

void upgrade(node *prev, node *cur, int left, int right, int p){
    if(left + 1 == right){
        cur -> sum += 1;
        return;
    }
    int middle = MID(left, right);
    if(p < middle){
        cur -> left = new node(prev -> left);
        upgrade(prev -> left, cur -> left, left, middle, p);
        cur -> right = prev -> right;
    }
    else{
        cur -> left = prev -> left;
        cur -> right = new node(prev -> right);
        upgrade(prev -> right, cur -> right, middle, right, p);
    }
    cur -> sum = (cur -> left -> sum) + (cur -> right -> sum);
}

int query(node *prev, node *cur, int left, int right, int k){
    if((cur -> sum) - (prev -> sum) < k)
        return -2;
    if(left + 1 == right)
        return left;
    int middle = MID(left, right);
    int ans = query(prev -> left, cur -> left, left, middle, k);
    return ans != -2 ? ans : query(prev -> right, cur -> right, middle, right, k);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    int q, v, l, r;
    cin >> n >> q;
    tree[ 0 ] = new node();
    build(tree[ 0 ], 0, n);
    for(int i = 1 ; i <= n ; i++){
        cin >> v;
        tree[ i ] = new node(tree[ i - 1 ]);
        upgrade(tree[ i - 1 ], tree[ i ], 0, n, v - 1);
    }
    while(q--)
        cin >> l >> r >> v, cout << query(tree[ l - 1 ], tree[ r ], 0, n, (r - l + 1) / v + 1) + 1 << endl;
	return 0;
}
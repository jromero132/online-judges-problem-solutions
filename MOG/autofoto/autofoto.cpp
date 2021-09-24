// Problem name: A - Autofoto
// Problem link: https://matcomgrader.com/problem/344/autofoto/
// Submission link: https://matcomgrader.com/submission/98391/

#include <stdio.h>
#include <iostream>
#include <map>

#define MAX 100005
#define INF 1 << 30
#define endl '\n'
#define pii pair<int, int>
#define find(m, v) m.find(v) != m.end()

using namespace std;

pii array[ MAX ];
int tree[ 4 * MAX ];

int min(int a, int b){
    return a < b ? a : b;
}

void build(int node, int nodeL, int nodeR){
    if(nodeL == nodeR){
        tree[ node ] = array[ nodeL ].second;
        return;
    }
    int nodeM = (nodeL + nodeR) / 2;
    build(2 * node + 1, nodeL, nodeM);
    build(2 * node + 2, nodeM + 1, nodeR);
    tree[ node ] = min(tree[ 2 * node + 1 ], tree[ 2 * node + 2]);
}

int query(int node, int nodeL, int nodeR, int L, int R){
    if(nodeL > R || nodeR < L)
        return INF;
    if(nodeL >= L && nodeR <= R)
        return tree[ node ];
    int nodeM = (nodeL + nodeR) / 2;
    if(R <= nodeM)
        return query(2 * node + 1, nodeL, nodeM, L, R);
    else if(L > nodeM)
        return query(2 * node + 2, nodeM + 1, nodeR, L, R);
    else
        return min(query(2 * node + 1, nodeL, nodeM, L, nodeM), query(2 * node + 2, nodeM + 1, nodeR, nodeM + 1, R));
}

map<int, int> nums;

int main()
{
    
    int n, t, a, b;
    scanf("%d", &n), n --;
    for(int i = 0 ; i <= n ; i++){
        scanf("%d", &array[ i ].first);
        if(nums.count(array[ i ].first))
            array[ nums[ array[ i ].first ] ].second = i;
        nums[ array[ i ].first ] = i;
        array[ i ].second = INF;
    }
    build(0, 0, n);
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &a, &b);
        printf("%s\n", query(0, 0, n, a - 1, b - 1) < b ? "SI" : "NO");
    }
    return 0;
}
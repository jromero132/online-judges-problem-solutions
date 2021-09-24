// Problem name: D - Valores Frecuentes
// Problem link: https://matcomgrader.com/problem/132/valores-frecuentes/
// Submission link: https://matcomgrader.com/submission/98365/

#include <iostream>

using namespace std;

#define MAX 200000
#define endl '\n'

struct node{
    int bestL, numL, bestR, numR, best, quant;
}tree[ 4 * MAX ];

int max(int a, int b){
    return a > b ? a : b;
}

node merge(node node1, node node2){
    node ans;
    ans.bestL = node1.bestL + ((node1.bestR == node1.quant && node1.numR == node2.numL) ? node2.bestL : 0);
    ans.numL = node1.numL;
    ans.bestR = node2.bestR + ((node2.bestL == node2.quant && node1.numR == node2.numL) ? node1.bestR : 0);
    ans.numR = node2.numR;
    ans.best = max(max(node1.best, node2.best), node1.numR == node2.numL ? node1.bestR + node2.bestL : 0);
    ans.quant = node1.quant + node2.quant;
    return ans;
}

int array[ MAX ];

void update(int n, int nodeL, int nodeR, int p){
    if(nodeL == nodeR){
        tree[ n ].best = tree[ n ].bestL = tree[ n ].bestR = tree[ n ].quant = 1;
        tree[ n ].numL = tree[ n ].numR = array[ p ];
        return;
    }
    int nodeM = (nodeL + nodeR) / 2;
    if(p <= nodeM)
        update(2 * n + 1, nodeL, nodeM, p);
    else
        update(2 * n + 2, nodeM + 1, nodeR, p);
    tree[ n ] = merge(tree[ 2 * n + 1 ], tree[ 2 * n + 2 ]);
}

node query(int n, int nodeL, int nodeR, int L, int R){
    if(nodeL == L && nodeR == R)
        return tree[ n ];
    int nodeM = (nodeL + nodeR) / 2;
    if(R <= nodeM)
        return query(2 * n + 1, nodeL, nodeM, L, R);
    else if(L > nodeM)
        return query(2 * n + 2, nodeM + 1, nodeR, L, R);
    else
        return merge(query(2 * n + 1, nodeL, nodeM, L, nodeM), query(2 * n + 2, nodeM + 1, nodeR, nodeM + 1, R));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, t, a, b;
    while(cin >> n && n){
        n--;
        cin >> t;
        for(int i = 0 ; i <= n ; i++){
            cin >> array[ i ];
            update(0, 0, n, i);
        }
        while(t--){
            cin >> a >> b;
            cout << query(0, 0, n, a - 1, b - 1).best << endl;
        }
    }
    return 0;
}
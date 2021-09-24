// Problem name: A - Intervalo de Suma Máxima
// Problem link: https://matcomgrader.com/problem/5751/intervalo-de-suma-maxima/
// Submission link: https://matcomgrader.com/submission/98363/

#include <iostream>

using namespace std;

#define MAX 250000
#define endl '\n'

struct node{
    int bestL, bestR, best, sum;
}tree[ 4 * MAX ];

int max(int a, int b){
    return a > b ? a : b;
}

node merge(node node1, node node2){
    node ans;
    ans.bestL = max(node1.bestL, node1.sum + node2.bestL);
    ans.bestR = max(node2.bestR, node2.sum + node1.bestR);
    ans.best = max(max(node1.best, node2.best), node1.bestR + node2.bestL);
    ans.sum = node1.sum + node2.sum;
    return ans;
}

int array[ MAX ];

void update(int n, int nodeL, int nodeR, int p){
    if(nodeL == nodeR){
        tree[ n ].best = tree[ n ].bestL = tree[ n ].bestR = tree[ n ].sum = array[ p ];
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
    int n, t, a, b;
    cin >> n, n--;
    for(int i = 0 ; i <= n ; i++){
        cin >> array[ i ];
        update(0, 0, n, i);
    }
    cin >> t;
    while(t--){
        cin >> a >> b;
        cout << query(0, 0, n, a - 1, b - 1).best << endl;
    }
    return 0;
}
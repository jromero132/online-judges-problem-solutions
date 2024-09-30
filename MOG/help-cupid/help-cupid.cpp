// Problem name: H - Help cupid
// Problem link: https://matcomgrader.com/problem/9314/help-cupid/
// Submission link: https://matcomgrader.com/submission/121275/

#include <bits/stdc++.h>

#define MAX (int)(1e3 + 1)

using namespace std;

typedef long long ll;

int array[ MAX ], match[ MAX ];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, sol1 = 0, sol2 = 0;
    cin >> n;
    for(int i = 0 ; i < n ; cin >> array[ i++ ]);
    sort(array, array + n);
    n--;
    for(int i = 0 ; i < n ; i += 2)
        sol1 += min(abs(array[ i ] - array[ i + 1 ]), 24 - abs(array[ i ] - array[ i + 1 ]));
    for(int i = 1 ; i < n ; i += 2)
        sol2 += min(abs(array[ i ] - array[ i + 1 ]), 24 - abs(array[ i ] - array[ i + 1 ]));
    sol2 += min(abs(array[ 0 ] - array[ n ]), 24 - abs(array[ 0 ] - array[ n ]));
    cout << min(sol1, sol2) << endl;
    return 0;
}
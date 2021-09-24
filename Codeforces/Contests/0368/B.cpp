// Problem name: Sereja and Suffixes
// Problem link: https://codeforces.com/contest/368/problem/B
// Submission link: https://codeforces.com/contest/368/submission/20929281

#include <iostream>

#define MAX (int)(1e5 + 5)
#define endl '\n'

using namespace std;

int DP[ MAX ], array[ MAX ], app[ MAX ];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++)
        cin >> array[ i ];
    for(int i = n - 1 ; i >= 0 ; i--)
        DP[ i ] = DP[ i + 1 ] + (app[ array[ i ] ] > 0 ? 0 : 1), app[ array[ i ] ] = 1;
    for(int i = 0 ; i < m ; i++)
        cin >> n, cout << DP[ --n ] << endl;
    return 0;
}
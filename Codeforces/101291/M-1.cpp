// Problem name: Zigzag
// Problem link: https://codeforces.com/gym/101291/problem/M
// Submission link: https://codeforces.com/gym/101291/submission/37240288

#include <bits/stdc++.h>

#define MAX ((int)51)
#define endl '\n'

using namespace std;

int num[ MAX ], DP[ MAX ][ 2 ];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(DP, 0, sizeof(DP));
    int n, ans = 0;
    cin >> n;
    for(int i = 0 ; i < n ; i++)
        cin >> num[ i ];
    for(int i = 0 ; i < n ; i++){
        DP[ i ][ 0 ] = max(1, DP[ i ][ 0 ]);
        DP[ i ][ 1 ] = max(1, DP[ i ][ 1 ]);
        ans = max(ans, max(DP[ i ][ 0 ], DP[ i ][ 1 ]));
        for(int j = i + 1 ; j < n ; j++){
            if(num[ i ] > num[ j ])
                DP[ j ][ 0 ] = max(DP[ j ][ 0 ], DP[ i ][ 1 ] + 1);
            else if(num[ i ] < num[ j ])
                DP[ j ][ 1 ] = max(DP[ j ][ 1 ], DP[ i ][ 0 ] + 1);
            else{
                DP[ j ][ 0 ] = max(DP[ j ][ 0 ], DP[ i ][ 0 ]);
                DP[ j ][ 1 ] = max(DP[ j ][ 1 ], DP[ i ][ 1 ]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
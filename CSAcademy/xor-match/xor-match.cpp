// Problem name: Xor Match
// Problem link: https://csacademy.com/contest/archive/task/xor-match/
// Submission link: https://csacademy.com/submission/1407507/

#include <bits/stdc++.h>

#define MAX ((int)1000)
#define MOD ((int)1000000007)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define endl '\n'

using namespace std;

int a[ MAX ], b[ MAX ];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m, ans = 0;
    cin >> n >> m;
    for(int i = 0 ; i < n ; cin >> a[ i++ ]);
    for(int i = 0 ; i < m ; cin >> b[ i++ ]);
    for(int k = 0 ; k <= m - n ; k++){
        bool ok = 1;
        for(int i = 0 ; i < n ; i++)
            if(!(a[ i ] ^ b[ i + k ])){
                ok = 0;
                break;
            }
        if(ok)
            ans++;
    }
    cout << ans << endl;
    return 0;
}
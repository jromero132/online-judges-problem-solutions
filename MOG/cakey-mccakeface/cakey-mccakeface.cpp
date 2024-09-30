// Problem name: A - Cakey McCakeFace
// Problem link: https://matcomgrader.com/problem/9488/cakey-mccakeface/
// Submission link: https://matcomgrader.com/submission/124058/

#include <bits/stdc++.h>

#define MAX ((int)10000)
#define F first
#define S second
#define endl '\n'

using namespace std;

typedef long long ll;

ll a[ MAX ], b[ MAX ];
map<ll, ll> s;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n >> m;
    for(int i = 0 ; i < n ; cin >> a[ i++ ]);
    for(int i = 0 ; i < m ; cin >> b[ i++ ]);
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < m ; j++){
            if(a[ i ] > b[ j ])
                continue;
            s[ b[ j ] - a[ i ] ]++;
        }
    ll ans = 0, k = 0;
    for(auto v : s){
        if(v.S > k || (v.S == k && v.F < ans))
            ans = v.F, k = v.S;
    }
    cout << ans << endl;
    return 0;
}
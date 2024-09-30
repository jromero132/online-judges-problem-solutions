// Problem name: Tea Queue
// Problem link: https://codeforces.com/contest/920/problem/B
// Submission link: https://codeforces.com/contest/920/submission/34955404

#include <bits/stdc++.h>

#define MAX ((int)1001)
#define MOD ((int)1000000007)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define mod(x, y) (((x) % (y) + (y)) % (y))
#define POPCOUNT(x) __builtin_popcount(x)
#define gcd(a, b) __gcd(a, b)
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

int ans[ MAX ];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    int t, n, l, r, now;
    for(cin >> t ; t-- ; ){
        cin >> n;
        cin >> l >> r;
        now = l + 1;
        ans[ 0 ] = l;
        for(int i = 1 ; i < n ; i++){
            cin >> l >> r;
            if(r < now){
                ans[ i ] = 0;
                continue;
            }
            ans[ i ] = max(now, l);
            now = ans[ i ] + 1;
        }
        cout << ans[ 0 ];
        for(int i = 1 ; i < n ; cout << ' ' << ans[ i++ ]);
        cout << endl;
    }
	return 0;
}
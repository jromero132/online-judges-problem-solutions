// Problem name: Old Floppy Drive 
// Problem link: https://codeforces.com/contest/1490/problem/G
// Submission link: https://codeforces.com/contest/1490/submission/121526144

#include <bits/stdc++.h>

#define pb push_back
#define lb lower_bound
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define print(x) cout << (x)
#define FOR(i, begin, end) for(__typeof(begin) i = (begin) ; i < (end) ; ++i)
#define F0R(i, end) for(int i = 0 ; i < (end) ; ++i)

using namespace std;

template<typename T> void read(T &x){ cin >> x; }
template<typename T, typename... Args> void read(T &x, Args&... args){ read(x); read(args...); }

typedef long long ll;
typedef vector<ll> vl;

void solve(){
    int n, m, a;
    read(n, m);
    vl sum(n + 1, 0), inc_sum = { 0 }, pos = { 0 };
    FOR(i, 1, n + 1){
        read(a);
        sum[ i ] = sum[ i - 1 ] + a;
        if(sum[ i ] > inc_sum[ sz(inc_sum) - 1 ]){
            inc_sum.pb(sum[ i ]);
            pos.pb(i - 1);
        }
    }
    F0R(i, m){
        read(a);
        if(sz(inc_sum) == 1 || (a > inc_sum[ sz(inc_sum) - 1 ] && sum[ n ] <= 0)){
            print(-1);
            print(" \n"[ i == m - 1 ]);
            continue;
        }
        ll k = sum[ n ] > 0 ? max(0LL, a - inc_sum[ sz(inc_sum) - 1 ] + sum[ n ] - 1) / sum[ n ] : 0;
        ll ans = n * k;
        a -= k * sum[ n ];
        ans += pos[ lb(all(inc_sum), a) - inc_sum.begin() ];
        print(ans);
        print(" \n"[ i == m - 1 ]);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    read(t);
    F0R(i, t)
        solve();
    return 0;
}
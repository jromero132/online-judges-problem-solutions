// Problem name: Air Conditioners
// Problem link: https://codeforces.com/contest/1547/problem/E
// Submission link: https://codeforces.com/contest/1547/submission/122025773

#include <bits/stdc++.h>

#define f first
#define s second
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define print(x) cout << (x)
#define FOR(i, begin, end) for(__typeof(begin) i = (begin) ; i < (end) ; ++i)
#define F0R(i, end) for(int i = 0 ; i < (end) ; ++i)
#define F0Rd(i, begin) for(__typeof(begin) i = (begin) - 1 ; i >= 0 ; --i)

using namespace std;

template<typename T> void read(T &x){ cin >> x; }
template<typename T, typename... Args> void read(T &x, Args&... args){ read(x); read(args...); }

typedef pair<int, int> pii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<pii> vii;

void solve(){
    int n, k;
    read(n, k);
    vii v(k);
    vb used(k, 1);
    F0R(i, k)
        read(v[ i ].f);
    F0R(i, k)
        read(v[ i ].s);
    sort(all(v));
    int left = 0, right = sz(v) - 1;
    for(int i = 1, j = right - 1 ; j >= 0 ; ++i, --j){

        if(v[ left ].s + v[ i ].f - v[ left ].f <= v[ i ].s)
            used[ i ] = 0;
        else
            left = i;
        if(v[ right ].s + v[ right ].f - v[ j ].f <= v[ j ].s)
            used[ j ] = 0;
        else
            right = j;
    }
    int p = 0;
    F0R(i, k)
        if(used[ i ])
            swap(v[ p++ ], v[ i ]);
    vi ans(n);
    F0Rd(i, v[ 0 ].f)
        ans[ i ] = v[ 0 ].f - i - 1 + v[ 0 ].s;
    FOR(i, v[ p - 1 ].f - 1, sz(ans))
        ans[ i ] = i - v[ p - 1 ].f + 1 + v[ p - 1 ].s;
    F0R(i, p - 1){
        FOR(j, v[ i ].f - 1, v[ i + 1 ].f){
            ans[ j ] = min(j - v[ i ].f + 1 + v[ i ].s, v[ i + 1 ].f - j - 1 + v[ i + 1 ].s);
        }
    }
    F0R(i, n){
        print(ans[ i ]);
        print(" \n"[ i == n - 1 ]);
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
// Problem name: Restoring the Permutation
// Problem link: https://codeforces.com/contest/1506/problem/E
// Submission link: https://codeforces.com/contest/1506/submission/121348308

#include <bits/stdc++.h>

#define EPS ((double)1e-15)
#define INF ((int)1e9)

#define bits __builtin_popcount
#define clz __builtin_clz
#define ctz __builtin_ctz
#define endl '\n'
#define gcd __gcd
#define mp make_pair
#define mt make_tuple
#define f first
#define s second
#define pq priority_queue
#define eb emplace_back
#define pb push_back
#define lb lower_bound
#define ub upper_bound

#define all(x) (x).begin(), (x).end()
#define len(x) (int)(x).length()
#define sz(x) (int)(x).size()

#define print(x) cout << (x)
#define prints(x) cout << (x) << ' '
#define printl(x) cout << (x) << endl
#define readv(v) for(auto &__x : v) cin >> __x
#define readv2(v) for(auto &__row : v) for(auto &__x : __row) cin >> __x

#define FOR(i, begin, end) for(__typeof(begin) i = (begin) ; i < (end) ; ++i)
#define F0R(i, end) for(int i = 0 ; i < (end) ; ++i)
#define FORv(i, begin, end, v) for(__typeof(begin) i = (begin) ; i < (end) ; i += v)
#define FORd(i, begin, end) for(__typeof(begin) i = (begin) - 1 ; i >= (end) ; --i)
#define F0Rd(i, begin) for(__typeof(begin) i = (begin) - 1 ; i >= 0 ; --i)
#define FORdv(i, begin, end, v) for(__typeof(begin) i = (begin) - 1 ; i >= (end) ; i -= v)
#define trav(x, v) for(auto &x : v)

#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
#define urd(a, b) uniform_real_distribution<double>(a, b)(rng)

using namespace std;

#define what_is(x) cout << __LINE__ << ": " << #x << " = " << (x) << endl
#define here cout << "\t\there!" << endl
template<typename T> void debug(T &x){ cout << (x) << endl; }
template<typename T, typename... Args> void debug(T x, Args&... args){ debug(x); cout << ' '; debug(args...); }

template<typename T> void read(T &x){ cin >> x; }
template<typename T, typename... Args> void read(T &x, Args&... args){ read(x); read(args...); }

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef pair<ll, int> pll;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
    int n;
    read(n);
    vi v(n), rem, ans1(n, 0), ans2(n, 0);
    readv(v);
    int m = 0;
    set<int> s;
    F0R(i, n){
        if(v[ i ] != m){
            ans1[ i ] = ans2[ i ] = v[ i ];
            FOR(j, m + 1, v[ i ])
                rem.pb(j), s.insert(j);
        }
        m = v[ i ];
    }
    int p = 0, val;
    F0R(i, n){
        if(!ans1[ i ]){
            val = *(--s.lb(m));
            ans1[ i ] = rem[ p ], ans2[ i ] = val, ++p;
            s.erase(val);
        }
        else
            m = ans1[ i ];
    }
    F0R(i, n){
        print(ans1[ i ]);
        print(" \n"[ i == n - 1 ]);
    }
    F0R(i, n){
        print(ans2[ i ]);
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
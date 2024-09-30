// Problem name: Double-ended Strings
// Problem link: https://codeforces.com/contest/1506/problem/C
// Submission link: https://codeforces.com/contest/1506/submission/121346323

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
    string s1, s2;
    read(s1, s2);
    int ans = INF;
    F0R(b1, len(s1)){
        F0R(l1, len(s1) - b1){
            F0R(b2, len(s2)){
                F0R(l2, len(s2) - b2){
                    if(s1.substr(b1, l1 + 1) == s2.substr(b2, l2 + 1)){
                        ans = min(ans, len(s1) - l1 + len(s2) - l2 - 2);
                    }
                }
            }
        }
    }
    printl(min(ans, len(s1) + len(s2)));
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
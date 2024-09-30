// Problem name: Spy Detected!
// Problem link: https://codeforces.com/contest/1512/problem/A
// Submission link: https://codeforces.com/contest/1512/submission/121293427

// Testing randomized solution

#include <bits/stdc++.h>

#define printl(x) cout << (x) << endl
#define readv(v) for(auto &__x : v) cin >> __x
#define F0R(i, end) for(int i = 0 ; i < (end) ; ++i)
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

using namespace std;

template<typename T> void read(T &x){ cin >> x; }
template<typename T, typename... Args> void read(T &x, Args&... args){ read(x); read(args...); }

typedef vector<int> vi;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int SAMPLES = 10000;

void solve(){
    int n;
    read(n);
    vi v(n);
    readv(v);

    --n;
    int p1, p2, p3;
    F0R(i, SAMPLES){
        p1 = uid(0, n);
        do{
            p2 = uid(0, n);
        } while(p2 == p1);
        do{
            p3 = uid(0, n);
        } while(p3 == p1 || p3 == p2);
        if(min({ v[ p1 ], v[ p2 ], v[ p3 ] }) != max({ v[ p1 ], v[ p2 ], v[ p3 ] })){
            if(v[ p1 ] == v[ p2 ])
                printl(p3 + 1);
            else if(v[ p1 ] == v[ p3 ])
                printl(p2 + 1);
            else
                printl(p1 + 1);
            return;
        }
    }
    assert(0);
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
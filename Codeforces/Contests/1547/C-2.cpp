// Problem name: Pair Programming
// Problem link: https://codeforces.com/contest/1547/problem/C
// Submission link: https://codeforces.com/contest/1547/submission/122016313

#include <bits/stdc++.h>

#define pb push_back
#define sz(x) (int)(x).size()
#define print(x) cout << (x)
#define printl(x) cout << (x) << endl
#define readv(v) for(auto &__x : v) cin >> __x
#define F0R(i, end) for(int i = 0 ; i < (end) ; ++i)

using namespace std;

template<typename T> void read(T &x){ cin >> x; }
template<typename T, typename... Args> void read(T &x, Args&... args){ read(x); read(args...); }

typedef vector<int> vi;

void solve(){
    int k, n, m;
    read(k, n, m);
    vi a(n), b(m);
    readv(a);
    readv(b);
    vi ans;
    for(int p1 = 0, p2 = 0 ; p1 < sz(a) || p2 < sz(b) ; ){
        if(p1 < sz(a) && a[ p1 ] <= k)
            ans.pb(a[ p1 ]), k += a[ p1++ ] == 0;
        else if(p2 < sz(b) && b[ p2 ] <= k)
            ans.pb(b[ p2 ]), k += b[ p2++ ] == 0;
        else{
            printl(-1);
            return;
        }
    }
    F0R(i, sz(ans)){
        print(ans[ i ]);
        print(" \n"[ i == sz(ans) - 1 ]);
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
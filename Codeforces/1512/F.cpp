// Problem name: Education
// Problem link: https://codeforces.com/contest/1512/problem/F
// Submission link: https://codeforces.com/contest/1512/submission/121297312

#include <bits/stdc++.h>

#define INF ((int)1e9)
#define printl(x) cout << (x) << endl
#define readv(v) for(auto &__x : v) cin >> __x
#define F0R(i, end) for(int i = 0 ; i < (end) ; ++i)

using namespace std;

template<typename T> void read(T &x){ cin >> x; }
template<typename T, typename... Args> void read(T &x, Args&... args){ read(x); read(args...); }

typedef vector<int> vi;

void solve(){
    int n, c;
    read(n, c);
    vi a(n), b(n - 1);
    readv(a);
    readv(b);
    int days = INF, cur = 0, next, earn = 0, need;
    F0R(i, n){
        need = c - earn;
        next = need / a[ i ] + (need % a[ i ] != 0);
        days = min(days, cur + next);

        if(i < n - 1){
            need = max(0, b[ i ] - earn);
            next = need / a[ i ] + (need % a[ i ] != 0);
            cur += next + 1;
            earn += next * a[ i ];
            earn -= b[ i ];
        }
        if(earn >= c || cur >= INF)
            break;
    }
    printl(days);
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
// Problem name: Spy Detected!
// Problem link: https://codeforces.com/contest/1512/problem/A
// Submission link: https://codeforces.com/contest/1512/submission/121284645

#include <bits/stdc++.h>

#define mt make_tuple
#define printl(x) cout << (x) << endl
#define F0R(i, end) for(int i = 0 ; i < (end) ; ++i)

using namespace std;

template<typename T> void read(T &x){ cin >> x; }
template<typename T, typename... Args> void read(T &x, Args&... args){ read(x); read(args...); }

void solve(){
    int n, a, b, c;
    read(n, a, b);
    bool found = 0;
    F0R(i, n - 2){
        read(c);
        if(!found && a != b){
            found = 1;
            printl(a != c ? i + 1 : i + 2);
        }
        tie(a, b) = mt(b, c);
    }
    if(!found)
        printl(n);
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
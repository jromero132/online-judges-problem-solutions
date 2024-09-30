// Problem name: Double-ended Strings
// Problem link: https://codeforces.com/contest/1506/problem/C
// Submission link: https://codeforces.com/contest/1506/submission/121350026

#include <bits/stdc++.h>

#define INF ((int)1e9)
#define len(x) (int)(x).length()
#define printl(x) cout << (x) << endl
#define F0R(i, end) for(int i = 0 ; i < (end) ; ++i)

using namespace std;

template<typename T> void read(T &x){ cin >> x; }
template<typename T, typename... Args> void read(T &x, Args&... args){ read(x); read(args...); }

void solve(){
    string s1, s2;
    read(s1, s2);
    int ans = INF;
    F0R(b1, len(s1)){
        F0R(l, len(s1) - b1){
            F0R(b2, len(s2) - l){
                if(s1.substr(b1, l + 1) == s2.substr(b2, l + 1)){
                    ans = min(ans, len(s1) + len(s2) - 2 * (l + 1));
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
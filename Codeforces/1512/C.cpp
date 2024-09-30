// Problem name: A-B Palindrome
// Problem link: https://codeforces.com/contest/1512/problem/C
// Submission link: https://codeforces.com/contest/1512/submission/121284157

#include <bits/stdc++.h>

#define endl '\n'
#define len(x) (int)(x).length()
#define printl(x) cout << (x) << endl
#define F0R(i, end) for(int i = 0 ; i < (end) ; ++i)

using namespace std;

template<typename T> void read(T &x){ cin >> x; }
template<typename T, typename... Args> void read(T &x, Args&... args){ read(x); read(args...); }

void solve(){
    int a, b, q = 0;
    string s;
    read(a, b, s);
    for(int i = 0, j = len(s) - 1 ; i <= j ; ++i, --j){
        a -= (s[ i ] == '0') + (i != j && s[ j ] == '0');
        b -= (s[ i ] == '1') + (i != j && s[ j ] == '1');
        q += (s[ i ] == '?') + (i != j && s[ j ] == '?');
        if(s[ i ] != s[ j ]){
            if(s[ i ] <= '1' && s[ j ] <= '1'){
                printl(-1);
                return;
            }
            char c = min(s[ i ], s[ j ]);
            a -= c == '0';
            b -= c == '1';
            s[ i ] = s[ j ] = c;
            --q;
        }
    }
    if(a < 0 || b < 0 || a + b != q){
        printl(-1);
        return;
    }
    for(int i = 0, j = len(s) - 1 ; i < j ; ++i, --j){
        if(s[ i ] == '?'){
            if(a >= 2)
                s[ i ] = s[ j ] = '0', a -= 2;
            else if(b >= 2)
                s[ i ] = s[ j ] = '1', b -= 2;
            else{
                printl(-1);
                return;
            }
        }
    }
    if((len(s) & 1) && s[ len(s) >> 1 ] == '?')
        s[ len(s) >> 1 ] = a > 0 ? (--a, '0') : (--b, '1');
    !a && !b ? printl(s) : printl(-1);
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
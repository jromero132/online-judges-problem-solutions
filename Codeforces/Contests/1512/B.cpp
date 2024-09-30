// Problem name: Almost Rectangle
// Problem link: https://codeforces.com/contest/1512/problem/B
// Submission link: https://codeforces.com/contest/1512/submission/121284452

#include <bits/stdc++.h>

#define f first
#define s second
#define eb emplace_back
#define printl(x) cout << (x) << endl
#define readv(v) for(auto &__x : v) cin >> __x
#define F0R(i, end) for(int i = 0 ; i < (end) ; ++i)
#define trav(x, v) for(auto &x : v)

using namespace std;

template<typename T> void read(T &x){ cin >> x; }
template<typename T, typename... Args> void read(T &x, Args&... args){ read(x); read(args...); }

typedef pair<int, int> pii;
typedef vector<string> vs;

void solve(){
    int n, a, b, c;
    read(n);
    vs v(n);
    readv(v);
    vector<pii> pos;
    F0R(i, n){
        F0R(j, n){
            if(v[ i ][ j ] == '*'){
                pos.eb(i, j);
            }
        }
    }
    if(pos[ 0 ].f == pos[ 1 ].f){
        int x = pos[ 0 ].f == 0 ? n - 1 : 0;
        v[ x ][ pos[ 0 ].s ] = v[ x ][ pos[ 1 ].s ] = '*';
    }
    else if(pos[ 0 ].s == pos[ 1 ].s){
        int y = pos[ 0 ].s == 0 ? n - 1 : 0;
        v[ pos[ 0 ].f ][ y ] = v[ pos[ 1 ].f ][ y ] = '*';
    }
    else{
        v[ pos[ 0 ].f ][ pos[ 1 ].s ] = v[ pos[ 1 ].f ][ pos[ 0 ]. s ] = '*';
    }
    trav(x, v){
        printl(x);
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
// Problem name: Epic Transformation
// Problem link: https://codeforces.com/contest/1506/problem/D
// Submission link: https://codeforces.com/contest/1506/submission/121350767

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define printl(x) cout << (x) << endl
#define readv(v) for(auto &__x : v) cin >> __x
#define FOR(i, begin, end) for(__typeof(begin) i = (begin) ; i < (end) ; ++i)
#define F0R(i, end) for(int i = 0 ; i < (end) ; ++i)

using namespace std;

template<typename T> void read(T &x){ cin >> x; }

typedef vector<int> vi;

void solve(){
    int n;
    read(n);
    vi v(n);
    readv(v);
    sort(all(v));
    int r = 0, p = 1;
    FOR(i, 1, n){
        if(v[ i ] != v[ i - 1 ])
            r = max(r, p), p = 0;
        ++p;
    }
    r = max(r, p) << 1;
    if(r >= n)
        printl(r - n);
    else
        printl(n & 1);
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
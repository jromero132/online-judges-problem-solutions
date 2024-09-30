// Problem name: Triangular Paths
// Problem link: https://codeforces.com/contest/1506/problem/F
// Submission link: https://codeforces.com/contest/1506/submission/121369332

#include <bits/stdc++.h>

#define f first
#define s second
#define all(x) (x).begin(), (x).end()
#define printl(x) cout << (x) << endl
#define F0R(i, end) for(int i = 0 ; i < (end) ; ++i)

using namespace std;

template<typename T> void read(T &x){ cin >> x; }
typedef pair<int, int> pii;
typedef vector<pii> vii;

int cost(int r1, int c1, int r2, int c2){
    if(r1 - c1 == r2 - c2)
        return ((r1 + c1) & 1) ? 0 : (r2 - r1);
    int r3 = r2 - r1 + 1, c3 = c2 - c1 + 1;
    return (r3 - c3 + ((r1 + c1) & 1)) >> 1;
}

void solve(){
    int n;
    read(n);
    vii v(n);
    F0R(i, n)
        read(v[ i ].f);
    F0R(i, n)
        read(v[ i ].s);
    sort(all(v));
    int ans = 0, r = 1, c = 1;
    F0R(i, n){
        ans += cost(r, c, v[ i ].f, v[ i ].s);
        tie(r, c) = v[ i ];
    }
    printl(ans);
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
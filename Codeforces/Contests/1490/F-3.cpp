// Problem name: Equalize the Array
// Problem link: https://codeforces.com/contest/1490/problem/F
// Submission link: https://codeforces.com/contest/1490/submission/121489363

#include <bits/stdc++.h>

#define INF ((int)1e9)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
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
    vi f;
    set<int> s;
    int b = 0;
    FOR(i, 1, n){
        if(v[ i ] != v[ i - 1 ]){
            f.pb(i - b);
            s.insert(i - b);
            b = i;
        }
    }
    f.pb(sz(v) - b);
    s.insert(sz(v) - b);
    int ans = INF;
    for(auto it = s.begin() ; it != s.end() ; ++it){
        int cur = 0;
        F0R(i, sz(f)){
            if(f[ i ] < *it)
                cur += f[ i ];
            else
                cur += f[ i ] - *it;
        }
        ans = min(ans, cur);
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
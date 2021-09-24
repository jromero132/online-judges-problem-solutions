// Problem name: Equalize the Array
// Problem link: https://codeforces.com/contest/1490/problem/F
// Submission link: https://codeforces.com/contest/1490/submission/121489537

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
    map<int, int> f;
    int b = 0;
    FOR(i, 1, n){
        if(v[ i ] != v[ i - 1 ]){
            ++f[ i - b ];
            b = i;
        }
    }
    ++f[ sz(v) - b ];
    int ans = INF;
    for(auto it1 = f.begin() ; it1 != f.end() ; ++it1){
        int cur = 0;
        for(auto it2 = f.begin() ; it2 != f.end() ; ++it2){
            if((it1 -> first) <= (it2 -> first)){
                cur += ((it2 -> first) - (it1 -> first)) * (it2 -> second);
            }
            else{
                cur += (it2 -> first) * (it2 -> second);
            }
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
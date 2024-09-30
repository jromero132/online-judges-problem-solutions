// Problem name: Air Conditioners
// Problem link: https://codeforces.com/contest/1547/problem/E
// Submission link: https://codeforces.com/contest/1547/submission/122026298

#include <bits/stdc++.h>

#define INF ((int)2e9)
#define print(x) cout << (x)
#define readv(v) for(auto &__x : v) cin >> __x
#define F0R(i, end) for(int i = 0 ; i < (end) ; ++i)

using namespace std;

template<typename T> void read(T &x){ cin >> x; }
template<typename T, typename... Args> void read(T &x, Args&... args){ read(x); read(args...); }

typedef vector<int> vi;

void solve(){
    int n, k;
    read(n, k);
    vi a(k);
    readv(a);
    vi left(n, INF), right(n, INF);
    int t;
    F0R(i, k){
        read(t);
        left[ a[ i ] - 1 ] = right[ a[ i ] - 1 ] = t;
    }
    for(int i = 0, j = n - 1, cur_left = INF, cur_right = INF ; i < n ; ++i, --j){
        left[ i ] = min(cur_left + 1, left[ i ]);
        cur_left = left[ i ];
        right[ j ] = min(cur_right + 1, right[ j ]);
        cur_right = right[ j ];
    }
    F0R(i, n){
        print(min(left[ i ], right[ i ]));
        print(" \n"[ i == n - 1 ]);
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
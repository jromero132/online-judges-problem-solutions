// Problem name: Array Stabilization (GCD version)
// Problem link: https://codeforces.com/contest/1547/problem/F
// Submission link: https://codeforces.com/contest/1547/submission/122048303

#include <bits/stdc++.h>

#define clz __builtin_clz
#define gcd __gcd
#define eb emplace_back
#define pb push_back
#define sz(x) (int)(x).size()
#define printl(x) cout << (x) << endl
#define F0R(i, end) for(int i = 0 ; i < (end) ; ++i)
#define trav(x, v) for(auto &x : v)

using namespace std;

template<typename T> void read(T &x){ cin >> x; }
typedef vector<int> vi;

template<typename T>
struct sparse_table{
    vector<vector<T>> table;
    function<T(T, T)> f;

    sparse_table(function<T(T, T)> f, const vector<T> &v) : table(1, v){
        this -> f = f;
        for(int i = 1, p = 1 ; (p << 1) <= sz(v) ; p <<= 1, ++i){
            table.eb(sz(v) - (p << 1) + 1);
            for(int j = 0 ; j < sz(table[ i ]) ; ++j)
                table[ i ][ j ] = f(table[ i - 1 ][ j ], table[ i - 1 ][ j + p ]);
        }
    }

    T query(int a, int b, bool idempotent = 1){
        int p = 31 - clz(b - a);
        if(idempotent)
            return f(table[ p ][ a ], table[ p ][ b - (1 << p) ]);
        T ans = table[ p ][ a ];
        for(a += (1 << p) ; a != b ; a += (1 << p)){
            p = 31 - clz(b - a);
            ans = f(ans, table[ p ][ a ]);
        }
        return ans;
    }
};

bool check(sparse_table<int> &st, int n, int k){
    F0R(i, n)
        if(st.query(i, i + k + 1) != 1)
            return 0;
    return 1;
}

void solve(){
    int n;
    read(n);
    vi v(n);
    int g = 0;
    F0R(i, n){
        read(v[ i ]);
        g = gcd(g, v[ i ]);
    }
    trav(x, v)
        x /= g;
    F0R(i, n)
        v.pb(v[ i ]);
    sparse_table<int> st([](int a, int b){ return gcd(a, b); }, v);
    int l = 0, r = n, m;
    while(l < r){
        m = (l + r) >> 1;
        if(check(st, n, m))
            r = m;
        else
            l = m + 1;
    }
    printl(r);
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
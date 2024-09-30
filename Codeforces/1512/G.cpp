// Problem name: Short Task
// Problem link: https://codeforces.com/contest/1512/problem/G
// Submission link: https://codeforces.com/contest/1512/submission/121305733

#include <bits/stdc++.h>

#define INF ((int)1e9)
// #define endl '\n'
#define pb push_back
#define sz(x) (int)(x).size()
#define printl(x) cout << (x) << endl
#define F0R(i, end) for(int i = 0 ; i < (end) ; ++i)

using namespace std;

template<typename T> void read(T &x){ cin >> x; }

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int MAX = 10000001;
vi ans(MAX, INF);
vl sum(MAX, 1);

void prep(){
    vi p;
    for(int i = 2 ; i < MAX ; ++i){
        if(sum[ i ] == 1)
            p.pb(i);
        for(int j = 0 ; j < sz(p) && (ll)i * p[ j ] <= MAX ; ++j){
            sum[ i * p[ j ] ] = p[ j ];
            if(i % p[ j ] == 0)
                break;
        }
    }
    ans[ 1 ] = 1;
    for(int i = 2, n, s ; i < MAX ; ++i){
        if(sum[ i ] == 1){
            sum[ i ] += i;
        }
        else{
            for(n = i, s = 1 ; n % sum[ i ] == 0 ; n /= sum[ i ], s = s * sum[ i ] + 1);
            sum[ i ] = s * sum[ n ];
        }
        if(sum[ i ] < MAX)
            ans[ sum[ i ] ] = min(ans[ sum[ i ] ], i);
    }
}

void solve(){
    int c;
    read(c);
    printl(ans[ c ] == INF ? -1 : ans[ c ]);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    prep();
    int t;
    read(t);
    F0R(i, t)
        solve();
    return 0;
}
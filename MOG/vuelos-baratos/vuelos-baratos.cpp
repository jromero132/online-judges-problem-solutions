// Problem name: A - Vuelos baratos
// Problem link: https://matcomgrader.com/problem/9477/vuelos-baratos/
// Submission link: https://matcomgrader.com/submission/123353/

#include <bits/stdc++.h>

#define MAX ((int)100005)
#define MAX_K ((int)26)
#define MOD ((int)1000000007)
#define INF ((int)((1 << 31) - 1))
#define EPS ((int)1e-6)
#define pf push_front
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define mod(x) (((x) % MOD + MOD) % MOD)
#define modS(x) ((x) % MOD)
#define DAD(x) ((x) >> 1)
#define LEFT(x) ((x) << 1)
#define RIGHT(x) ((x) << 1 | 1)
#define gcd(a, b) __gcd(a, b)
#define POPCOUNT(x) __builtin_popcount(x)
#define CLZ(x) __builtin_clz(x)
#define CTZ(x) __builtin_ctz(x)

using namespace std;

typedef unsigned int uint;
typedef long long ll;

struct DisjointSets{
    ll n;
    vector<ll> p, s;

    DisjointSets(ll n) : n(n), p(n), s(n, 1){
        for(ll i = 0 ; i < n ; i++)
            p[ i ] = i;
    }

    ll Find(ll v){
        return p[ v ] == v ? v : p[ v ] = Find(p[ v ]);
    }

    void Merge(ll v1, ll v2){
        ll p1 = Find(v1);
        ll p2 = Find(v2);
        if(p1 == p2)
            return;
        if(s[ p1 ] > s[ p2 ]){
            s[ p1 ] += s[ p2 ];
            p[ p2 ] = p1;
        }
        else{
            s[ p2 ] += s[ p1 ];
            p[ p1 ] = p2;
        }
    }
};

typedef pair< ll, pair<ll, ll> > edge;

edge edges[ MAX ];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("sample.in", "r", stdin);
    //freopen("sample.out", "w", stdout);

    //cout.precision(8);
    //cout.flags(ios::fixed);

    ll n;
    cin >> n;
    DisjointSets ds(n);
    n--;
    for(ll i = 0 ; i < n ; i++){
        cin >> edges[ i ].S.F >> edges[ i ].S.S >> edges[ i ].F;
        edges[ i ].S.F--;
        edges[ i ].S.S--;
    }
    sort(edges, edges + n);
    ll ans = 0;
    for(ll i = 0 ; i < n ; i++){
        ans += ((ll)ds.s[ ds.Find(edges[ i ].S.F) ] * ds.s[ ds.Find(edges[ i ].S.S) ]) * edges[ i ].F;
        ds.Merge(edges[ i ].S.F, edges[ i ].S.S);
    }
    cout << ans + ((ll)n * (n + 1LL)) / 2LL - n << endl;
    return 0;
}
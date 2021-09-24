// Problem name: Mentors
// Problem link: https://codeforces.com/contest/978/problem/F
// Submission link: https://codeforces.com/contest/978/submission/38704780

#include <bits/stdc++.h>

#define MAX ((int)200001)
#define INF ((int)1000000000)
#define MOD ((ll)1000000007)
#define EPS ((double)1e-8)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define mod(x) ((x) % MOD)
#define modS(x) ((((x) % MOD) + MOD) % MOD)
#define DAD(x) ((x) >> 1)
#define LEFT(x) ((x) << 1)
#define RIGHT(x) ((x) << 1 | 1)
#define popcount __builtin_popcount
#define clz __builtin_clz
#define ctz __builtin_ctz
#define gcd __gcd
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

pii num[ MAX ];
int ans[ MAX ], quarrel[ MAX ];

bool cmp(pii a, pii b){
    return a.F != b.F ? a.F < b.F : 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("01.in", "r", stdin);
    //freopen("01.out", "w", stdout);

    int n, k, v, w;
    cin >> n >> k;
    for(int i = 0 ; i < n ; i++)
        cin >> num[ i ].F, num[ i ].S = i;
    set< pii > p;
    while(k--){
        cin >> v >> w;
        if(num[ --v ].F > num[ --w ].F)
            swap(v, w);
        if(num[ v ].F != num[ w ].F)
            quarrel[ w ]++;
    }
    sort(num, num + n);
    for(int i = 0 ; i < n ; i++)
        ans[ num[ i ].S ] = (lower_bound(num, num + i + 1, num[ i ], cmp) - num) - quarrel[ num[ i ].S ];
    for(int i = 0 ; i < n ; i++)
        cout << ans[ i ] << ' ';
    cout << endl;
    return 0;
}
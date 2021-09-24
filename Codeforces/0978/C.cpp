// Problem name: Letters
// Problem link: https://codeforces.com/contest/978/problem/C
// Submission link: https://codeforces.com/contest/978/submission/38165364

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

ll num[ MAX ];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("01.in", "r", stdin);
    //freopen("01.out", "w", stdout);

    int n, m;
    ll k;
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++)
        cin >> num[ i ], num[ i ] += num[ i - 1 ];
    while(m--){
        cin >> k;
        int p = lower_bound(num, num + n + 1, k) - num;
        cout << p << ' ' << k - num[ p - 1 ] << endl;
    }
    return 0;
}
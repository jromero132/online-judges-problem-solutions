// Problem name: C - Minimizando
// Problem link: https://matcomgrader.com/problem/9197/minimizando/
// Submission link: https://matcomgrader.com/submission/116866/

#include <bits/stdc++.h>

#define MOD (int)(1e9 + 7)
#define MAX (int)(1e5 + 1)
#define INF (ll)(1e18)
#define EPS (double)(1e-7)
#define pb(x) push_back((x))
#define pf(x) push_front((x))
#define mp(x, y) make_pair((x), (y))
#define F first
#define S second
#define LEFT(i) ((i) << 1)
#define RIGHT(i) ((i) << 1 | 1)
#define FATHER(i) ((i) >> 1)
#define endl '\n'

#define FOR(i, n, m) for(int i = m ; i < n + m ; i++)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;

ll n, sum = 0, num[ MAX ];

ll dist(ll x){
    ll ans = 0;
    for(int i = 0 ; i < n ; i++)
        ans += abs(x - num[ i ]);
    return ans;
}

ll TernarySearch(){
    ll lo = 0, hi = INF;
    while(hi - lo > 1){
        ll mid = (hi + lo) >> 1;
        if(dist(mid) < dist(mid + 1))
             hi = mid;
        else
             lo = mid;
    }
    return ++lo;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    FOR(i, n, 0)
        cin >> num[ i ], sum += num[ i ];
    cout << dist(TernarySearch());
    return 0;
}
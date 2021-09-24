// Problem name: Theatre Square
// Problem link: https://codeforces.com/contest/1/problem/A
// Submission link: https://codeforces.com/contest/1/submission/27363695

#include <bits/stdc++.h>

#define MAX (int)(1e5 + 1)
#define MOD (int)(1e9 + 7)
#define INF (int)((1 << 31) - 1)
#define EPS (double)(1e-6)
#define pf(i) push_front(i)
#define pb(i) push_back(i)
#define mp(i, j) make_pair(i, j)
#define F first
#define S second
#define DAD(x) ((x) >> 1)
#define LEFT(x) ((x) << 1)      //0         ((x) << 1 | 1)      //1
#define RIGHT(x) ((x) << 1 | 1) //0         (((x) + 1) << 1)    //1
#define endl '\n'

#define FOR(i, n, m) for(int i = m ; i < n ; i++)
#define FORR(i, n, m) for(int i = n - 1 ; i >= m ; i--)
#define MODS(x) (((x) % MOD) + MOD) % MOD

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, m, a;
    cin >> n >> m >> a;
    cout << (ll)(ceil((double)n / a) * ceil((double)m / a)) << endl;
    return 0;
}
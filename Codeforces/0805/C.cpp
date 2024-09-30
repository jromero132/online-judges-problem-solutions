// Problem name: Find Amir
// Problem link: https://codeforces.com/contest/805/problem/C
// Submission link: https://codeforces.com/contest/805/submission/26850456

#include <bits/stdc++.h>

#define MOD (int)(2e5 + 1)
#define MAX (int)(1e6 + 3)
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

#define MOD(a, b) (((a) % (b) + (b)) % (b))
#define FOR(i, n, m) for(int i = m ; i < n + m ; i++)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    cout << (n - 1) / 2;
    return 0;
}
// Problem name: Help General
// Problem link: https://codeforces.com/contest/143/problem/D
// Submission link: https://codeforces.com/contest/143/submission/25735740

#include <bits/stdc++.h>

#define MOD (int)(1e9 + 7)
#define EPS (double)(1e-7)
#define MAX (int)(1e3 + 1)
#define pb(x) push_back((x))
#define pf(x) push_front((x))
#define mp(x, y) make_pair((x), (y))
#define INF (ll)(1e18)
#define LEFT(i) ((i) << 1)
#define RIGHT(i) ((i) << 1 | 1)
#define FATHER(i) ((i) >> 1)
#define F first
#define S second
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll n, m;

int sol(int n, int m){
    if(m > n)
        n ^= m ^= n ^= m;
    if(m == 1)
        return n;
    else if(m == 2)
        return 2 * (2 * (n / 4) + min(n % 4, 2));
    return m * n - m * n / 2;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    cout << sol(n, m);
    return 0;
}
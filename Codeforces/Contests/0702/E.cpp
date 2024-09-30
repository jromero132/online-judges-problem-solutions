// Problem name: Analysis of Pathes in Functional Graph
// Problem link: https://codeforces.com/contest/702/problem/E
// Submission link: https://codeforces.com/contest/702/submission/45431624

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int m[100005][34], go[100005][34];
ll sum[100005][34];

int main()
{
	//freopen("a.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(0);

	ll n, k;
	cin >> n >> k;
	vector<int> next(n), w(n);
	for (auto &i : next) cin >> i;
	for (auto &i : w) cin >> i;

	for (int u = 0; u < n; ++u)
	{
		m[u][0] = w[u];
		sum[u][0] = w[u];
		go[u][0] = next[u];
	}

	for (int i = 1; i < 34; ++i)
		for (int u = 0; u < n; ++u)
		{
			int v = go[u][i-1];
			m[u][i] = min(m[u][i-1], m[v][i-1]);
			sum[u][i] = sum[u][i-1] + sum[v][i-1];
			go[u][i] = go[v][i-1];
		}

	for (int i = 0; i < n; ++i)
	{
		ll s = 0, tk = k;
		int mn = numeric_limits<int>::max(), u = i;
		for (int j = 33; j >= 0; --j)
			if (tk - (1LL<<j) >= 0)
			{
				tk -= 1LL<<j;
				s += sum[u][j];
				mn = min(mn, m[u][j]);
				u = go[u][j];
			}
		cout << s << " " << mn << "\n";
	}

	return 0;
}
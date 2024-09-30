// Problem name: Simple Path
// Problem link: https://codeforces.com/gym/101353/problem/H
// Submission link: https://codeforces.com/gym/101353/submission/37261843

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll mod = 1000000007LL;

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL);

	int t;
	cin >> t;
	for (int j = 1; j <= t; ++j)
	{
		int n;
		cin >> n;
		vector<vector<pair<int, int>>> adj(n+1);
		for (int i = 1, u, v, w; i < n; ++i)
		{
			cin >> u >> v >> w;
			adj[u].push_back({v, w});
			adj[v].push_back({u, w});
		}

		ll ans = 0;

		vector<ll> sum(n+1), cnt(n+1), f(n+1);
		function<void(int, int)> dfs = [&](int u, int p)
		{
			++cnt[u];
			for (auto v : adj[u])
				if (v.first != p)
				{
					dfs(v.first, u);
					f[u] += f[v.first];
					f[u] %= mod;
					f[u] += ((sum[u] * cnt[v.first]) % mod + (cnt[u] * (sum[v.first] + v.second * cnt[v.first]) % mod) % mod) % mod;
					f[u] %= mod;
					sum[u] += (sum[v.first] + v.second * cnt[v.first] % mod) % mod;
					sum[u] %= mod;
					cnt[u] += cnt[v.first];
					cnt[u] %= mod;
				}
			//++cnt[u];
			//ans += sum[u];
			ans += f[u];
			ans %= mod;
		};

		dfs(1, -1);

		cout << "Case " << j << ": " << ans << "\n";
	}

    return 0;
}
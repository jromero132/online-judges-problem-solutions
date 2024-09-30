// Problem name: Keeping On Track
// Problem link: https://codeforces.com/gym/101673/problem/F
// Submission link: https://codeforces.com/gym/101673/submission/37980621

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;



int main()
{
	//freopen("a.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(0);

	int n;
	cin >> n;
	++n;
	vector<vector<int>> adj(n+1);
	for (int i = 1, u, v; i < n; ++i)
	{
		cin >> u >> v;
		++u, ++v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int> sz(n+1), parent(n+1);
	function<void(int, int)> dfs = [&](int u, int p)
	{
		++sz[u];
		for (auto v : adj[u])
			if (v != p)
			{
				dfs(v, u);
				parent[v] = u;
				sz[u] += sz[v];
			}
	};

	dfs(1, -1);
	vector<int> w;
	ll ans = 0;
	for (int u = 1; u <= n; ++u)
	{
		vector<int> a;
		if (u != 1) a.push_back(n-sz[u]);
		for (auto v : adj[u])
			if (v != parent[u])
				a.push_back(sz[v]);

		ll cur = 0, t = 0;
		for (auto i : a)
			t += i;
		for (auto i : a)
			cur += i*(n-i-1LL);
		cur /= 2;
		if (cur > ans)
		{
			ans = cur;
			w = a;
		}
	}

	cout << ans << " ";
	sort(w.begin(), w.end());
	ll cur = w.back();
	w.pop_back();
	if (!w.empty()) cur *= w.back();
	else cur = 0;
	cout << ans - cur;

	return 0;
}

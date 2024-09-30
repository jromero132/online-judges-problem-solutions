// Problem name: Carnival
// Problem link: https://codeforces.com/gym/101962/problem/D
// Submission link: https://codeforces.com/gym/101962/submission/45150554

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define F first
#define S second

bool mark[2005];
int all[2005];
vector<int> s[50005], s2[50005];

int main()
{
	//freopen("a.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n+1);
	for (int i = 0, u, v; i < m; ++i)
	{
		cin >> u >> v;
		adj[u].push_back(v);
	}

	function<void(int, vector<int>&)> dfs = [&dfs, &adj](int u, vector<int> &s)
	{
		s.push_back(u);
		mark[u] = true;
		for (auto v : adj[u])
			if (!mark[v])
				dfs(v, s);
	};

	vector<pair<int, int>> ans;
	for (int i = 1; i <= n; ++i)
	{
		int sz = adj[i].size();
		for (int j = 0; j < sz; ++j)
			s[j].clear(), s2[j].clear();

		memset(mark, 0, sizeof mark);
		mark[i] = true;
		int p = 0;
		for (auto v : adj[i])
		{
			if (!mark[v])
				dfs(v, s[p]);
			++p;
		}

		memset(mark, 0, sizeof mark);
		mark[i] = true;
		for (int j = sz-1; j >= 0; --j)
		{
			--p;
			if (!mark[adj[i][j]])
				dfs(adj[i][j], s2[p]);
		}

		memset(all, 0, sizeof all);
		for (int j = sz-1; j > 0; --j)
			for (auto u : s2[j])
				++all[u];

		for (int j = 0; j < sz; ++j)
		{
			int v = adj[i][j];
			if (!all[v])
				ans.push_back({ i, v });

			if (j+1 < sz)
				for (auto u : s2[j+1])
					--all[u];
			for (auto u : s[j])
				++all[u];
		}
	}

	cout << ans.size() << "\n";
	for (auto &i : ans)
		cout << i.F << " " << i.S << "\n";

	return 0;
}
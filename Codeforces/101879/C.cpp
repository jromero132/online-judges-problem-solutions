// Problem name: Promenade by the lake
// Problem link: https://codeforces.com/gym/101879/problem/C
// Submission link: https://codeforces.com/gym/101879/submission/45342569

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

typedef long long ll;
#define F first
#define S second

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	vector<int> deg(n+1);
	vector<vector<pair<int, int>>> adj(n+1);
	for (int i = 0, u, v; i < m; ++i)
	{
	    cin >> u >> v;
        deg[u] ^= 1, deg[v] ^= 1;
	}

	for (int i = 0, u, v; i < k; ++i)
	{
	    cin >> u >> v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
	}

	vector<bool> mark(n+1), used(k);
	function<int(int, int)> dfs = [&](int u, int p)
	{
        mark[u] = true;
        for (auto v : adj[u])
            if (!mark[v.F])
            {
                int ncur = dfs(v.F, u);
                if (ncur)
                {
                    used[v.S] = true;
                    deg[v.F] ^= 1;
                    deg[u] ^= 1;
                }
            }
        return deg[u];
	};

	for (int i = 1; i <= n; ++i)
        if (deg[i] && dfs(i, -1))
        {
            cout << "NO\n";
            return 0;
	    }

	cout << "YES\n";
	cout << accumulate(used.begin(), used.end(), 0) << "\n";
	for (int i = 1; i <= n; ++i)
	    for (auto v : adj[i])
	        if (used[v.S])
	            cout << i << " " << v.F << "\n", used[v.S] = 0;

	return 0;
}
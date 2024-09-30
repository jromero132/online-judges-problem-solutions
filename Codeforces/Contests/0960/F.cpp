// Problem name: Pathwalks
// Problem link: https://codeforces.com/contest/960/problem/F
// Submission link: https://codeforces.com/contest/960/submission/37110519

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


struct segment_tree
{
	int n;
	vector<int> st, lazy;

	segment_tree (int n) : n(n), st(4*n, 1), lazy(4*n) {}

	inline void push(int cur)
	{
		if (lazy[cur] != 0)
		{
			st[cur<<1] = max(st[cur<<1], lazy[cur]);
			st[cur<<1|1] = max(st[cur<<1|1], lazy[cur]);
			lazy[cur<<1] = max(lazy[cur<<1], lazy[cur]);
			lazy[cur<<1|1] = max(lazy[cur<<1|1], lazy[cur]);
			lazy[cur] = 0;
		}
	}

	void update(int cur, int b, int e, int l, int h, int v)
	{
		if (b >= l && e <= h)
		{
			st[cur] = max(st[cur], v);
			lazy[cur] = max(lazy[cur], v);
			return;
		}

		push(cur);
		int m = (b+e)>>1;
		if (l < m)
			update(cur<<1, b, m, l, h, v);
		if (m < h)
			update(cur<<1|1, m, e, l, h, v);
		st[cur] = max(st[cur<<1], st[cur<<1|1]);
	}

	int get(int cur, int b, int e, int p)
	{
		if (b+1 == e)
			return st[cur];
		push(cur);
		int m = (b+e)>>1;
		if (p < m)
			return get(cur<<1, b, m, p);
		return get(cur<<1|1, m, e, p);
	}

	int get(int p)
	{
		return get(1, 0, n, p);
	}

	void update(int l, int v)
	{
		update(1, 0, n, l, n, v);
	}
};


struct edge
{
	int v, w, id;
};

struct edge2
{
	int u, v, w, id;
};

int main()
{
	//freopen("a.txt", "r", stdin);
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<edge2> e2;
    vector<vector<edge>> e(n+1);
    for (int i = 0, u, v, w; i < m; ++i)
    {
    	cin >> u >> v >> w;
    	e[u].push_back({v, w, i});
    	e2.push_back({u, v, w, i});
    }

    vector<segment_tree*> data(n+1, NULL);
    for (int i = 1; i <= n; ++i)
    	data[i] = new segment_tree(e[i].size());

    sort(e2.begin(), e2.end(), [](edge2 &a, edge2 &b) { return a.w < b.w; });

    function<int(int, int)> f = [&](int u, int id)
	{
    	if (e[u].empty()) return -1;
    	int b = 0, ed = e[u].size() - 1;
    	while (b < ed)
    	{
    		int m = (b+ed)>>1;
    		if (e[u][m].id < id)
    			b = m+1;
    		else
    			ed = m;
    	}
    	if (e[u][b].id >= id)
    		return b;
    	return -1;
	};

    int ans = 0;
    for (int i = 0; i < m; ++i)
    {
    	vector<int> dp(1, data[e2[i].u]->get(f(e2[i].u, e2[i].id)));
    	int k = i;
    	while (k+1 < m && e2[k+1].w == e2[i].w)
    	{
    		++k;
    		dp.push_back(data[e2[k].u]->get(f(e2[k].u, e2[k].id)));
    	}

    	for (int j = i; j <= k; ++j)
    	{
    		int p = f(e2[j].v, e2[j].id+1);
    		if (p != -1) data[e2[j].v]->update(p, dp[j-i]+1);
    	}

    	ans = max(ans, *max_element(dp.begin(), dp.end()));

    	i = k;
    }

    cout << ans << "\n";

    return 0;
}
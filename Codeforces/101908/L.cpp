// Problem name: Subway Lines
// Problem link: https://codeforces.com/gym/101908/problem/L
// Submission link: https://codeforces.com/gym/101908/submission/44969591

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define F first
#define S second

struct seg_tree
{
	int n;
	vector<ll> st, lz;
	seg_tree(int n) : n(n), st(4*n), lz(4*n) {}
	void push(int cur, int b, int e, int m)
	{
		if (lz[cur] != 0)
		{
			st[cur<<1] += (m-b)*lz[cur];
			st[cur<<1|1] += (e-m)*lz[cur];
			lz[cur<<1] += lz[cur];
			lz[cur<<1|1] += lz[cur];
			lz[cur] = 0;
		}
	}
	ll query(int cur, int b, int e, int l, int h)
	{
		if (l <= b && e <= h)
			return st[cur];
		int m = (b+e)>>1;
		push(cur, b, e, m);
		ll ret = 0;
		if (l < m)
			ret += query(cur<<1, b, m, l, h);
		if (m < h)
			ret += query(cur<<1|1, m, e, l, h);
		return ret;
	}
	void update(int cur, int b, int e, int l, int h, int x)
	{
		if (l <= b && e <= h)
		{
			st[cur] += (e-b)*x;
			lz[cur] += x;
			return;
		}
		int m = (b+e) >> 1;
		push(cur, b, e, m);
		if (l < m)
			update(cur<<1, b, m, l, h, x);
		if (m < h)
			update(cur<<1|1, m, e, l, h, x);
		st[cur] = st[cur<<1] + st[cur<<1|1];
	}
	int query(int a, int b)
	{
		return query(1, 1, n+1, a, b+1);
	}
	void update(int a, int b, int x)
	{
		update(1, 1, n+1, a, b+1, x);
	}
};

struct heavy_light_descomposition
{
        int n;
        vector<vector<int>> G;
        vector<int> parent, depth, size, head, position;
        seg_tree abi;
        heavy_light_descomposition(int n) : n(n), G(n), parent(n, -1), depth(n), size(n), head(n), position(n), abi(n) {}

        void add_edge(int u, int v)
        {
            G[u].push_back(v);
            G[v].push_back(u);
        }

        void rootify(int r = 0)
        {
            vector<int> heavy(n, -1), Q(1, r);

            for (int i = 0, u; i < n; ++i)
            {
                size[u = Q[i]] = 1;
                for (auto v : G[u])
                    if (parent[u] != v)
                        Q.push_back(v), parent[v] = u, depth[v] = depth[u] + 1;
            }

            for (int i = n - 1, u; i >= 0; --i)
            {
                u = Q[i];
                for (auto v : G[u])
                    if (parent[u] != v)
                    {
                        size[u] += size[v];
                        if (heavy[u] == -1 || size[v] > size[heavy[u]])
                            heavy[u] = v;
                    }
            }

            for (int u = 0, pos = 0; u < n; ++u)
                if (u == r || heavy[parent[u]] != u)
                    for (int v = u; v != -1; v = heavy[v])
                        head[v] = u, position[v] = ++pos;
        }

        int lca(int u, int v)
        {
            while (head[u] != head[v])
            {
                if (depth[head[u]] < depth[head[v]])
                    swap(u, v);
                u = parent[head[u]];
            }
            return (depth[u] < depth[v] ? u : v);
        }

        ll query_up(int u, int v)
        {
            ll ans = 0;
            while (head[u] != head[v])
            {
                ans += abi.query(position[head[u]], position[u]);
                u = parent[head[u]];
            }
            return ans + abi.query(position[v], position[u]);
        }

        int query(int u, int v)
        {
            int L = lca(u, v);
            return query_up(u, L) + query_up(v, L) - query_up(L, L);
        }

        void update_up(int u, int v, int x)
		{
			while (head[u] != head[v])
			{
				abi.update(position[head[u]], position[u], x);
				u = parent[head[u]];
			}
			abi.update(position[v], position[u], x);
		}

        void update(int u, int v, int x)
        {
            int L = lca(u, v);
            update_up(u, L, x);
            update_up(v, L, x);
            update_up(L, L, -x);
        }
};

int main()
{
	//freopen("a.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(0);

	int n, q;
	cin >> n >> q;
	heavy_light_descomposition lca(n);
	for (int i = 1, u, v; i < n; ++i)
	{
		cin >> u >> v;
		lca.add_edge(--u, --v);
	}

	lca.rootify(0);

	for (int a, b, c, d; q--; )
	{
		cin >> a >> b >> c >> d;
		--a, --b, --c, --d;
		lca.update(a, b, 1);
		cout << lca.query(c, d) << "\n";
		lca.update(a, b, -1);
	}

	return 0;
}
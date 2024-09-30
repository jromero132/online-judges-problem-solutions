// Problem name: Help Conan
// Problem link: https://codeforces.com/gym/101778/problem/D
// Submission link: https://codeforces.com/gym/101778/submission/37288930

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ll mod = 1e9+7;

ll Pow(ll a, ll b)
{
	ll x = 1;
	for (; b > 0; b >>= 1)
	{
		if (b & 1) x = x*a%mod;
		a = a*a%mod;
	}
	return x;
}

struct edge
{
	int u, v, w;
};

struct union_find
{
	vector<int> p;

	union_find(int n) : p(n, -1) {}

	bool join(int u, int v)
	{
		if ((u = root(u)) == (v = root(v)))
			return false;
		if (p[u] > p[v])
			swap(u, v);
		p[u] += p[v];
		p[v] = u;
		return true;
	}

	int root(int u)
	{
		return p[u] < 0 ? u : p[u] = root(p[u]);
	}
};


int main()
{
	//freopen("a.txt", "r", stdin);
	ios_base::sync_with_stdio(false), cin.tie(NULL);

	int test;
	cin >> test;

	while (test--)
	{
		int n, m, k;
		cin >> n >> m >> k;
		vector<edge> e(m);
		for (auto &i : e)
			cin >> i.u >> i.v >> i.w, --i.u, --i.v;
		sort(e.begin(), e.end(), [](edge &a, edge &b) { return a.w < b.w; });
		vector<int> q(k);
		for (auto &i : q)
			cin >> i, --i;
		ll ans = numeric_limits<ll>::max();
		for (int i = 1; i < 1<<n; ++i)
		{
			ll cost = 0;
			union_find ds(n);
			for (auto &j : e)
				if ((i&1<<j.u) && (i&1<<j.v) && ds.join(j.u, j.v))
					cost += j.w;
			int p = ds.root(q[0]);
			bool can = true;
			for (auto j : q)
				can &= ds.root(j) == p;
			if (can) ans = min(ans, cost);
		}
		cout << ans << "\n";
	}

    return 0;
}
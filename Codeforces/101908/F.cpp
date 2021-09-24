// Problem name: Music Festival
// Problem link: https://codeforces.com/gym/101908/problem/F
// Submission link: https://codeforces.com/gym/101908/submission/44968185

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define F first
#define S second

struct st
{
	int a, b, k, d;
	bool operator<(const st &x) const
	{
		return b < x.b;
	}
};

struct segment_tree
{
    int n;
    vector<ll> a;

    segment_tree(int n = 1005) : n(n), a(2 * n) {}

    void update(int p, ll v)
    {
        for (a[p += n] = v; p /= 2;)
            a[p] = max(a[2 * p], a[2 * p + 1]);
    }

    ll query(int l, int r)
    {
        ll g = 0;

        for (l += n, r += n; l < r; l /= 2, r /= 2)
        {
            if (l & 1) g = max(g, a[l++]);
            if (r & 1) g = max(g, a[--r]);
        }

        return g;
    }
};

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0);

	int n;
	cin >> n;
	vector<st> q;
	for (int i = 0, m, a, b, k; i < n; ++i)
	{
		cin >> m;
		while (m--)
		{
			cin >> a >> b >> k;
			q.push_back({ a, b, k, i });
		}
	}

	sort(q.begin(), q.end());
	vector<segment_tree> dp(1<<n);

	int cnt = 0;
	for (auto &i : q)
		dp[1<<i.d].update(cnt++, i.k);

	st query = { 0, 0, 0, 0 };

	for (int i = 0; i < q.size(); ++i)
		for (int m = 1; m < 1<<n; ++m)
		{
			query.b = q[i].a;
			auto it = upper_bound(q.begin(), q.end(), query);
			if (it == q.begin()) continue;

			int p = prev(it) - q.begin();

			for (int h = m, iter = 2; iter--; h ^= 1<<q[i].d)
			{
				ll v = dp[h].query(0, p+1);
				ll old = dp[m].query(i, i+1);
				if (v != 0 && v+q[i].k > old)
					dp[m].update(i, v+q[i].k);
			}
		}

	ll ans = dp[(1<<n)-1].query(0, q.size());

	if (ans == 0)
		--ans;

	cout << ans << "\n";

	return 0;
}
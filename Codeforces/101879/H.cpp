// Problem name: Wine Production
// Problem link: https://codeforces.com/gym/101879/problem/H
// Submission link: https://codeforces.com/gym/101879/submission/45340398

#include <bits/stdc++.h>

#define endl '\n'
#define S second
#define F first

using namespace std;

typedef long long ll;

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>     // Including tree_order_statistics_node_update

using namespace __gnu_pbds;

typedef tree<pair<int, int>, null_type, greater<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int f[30001];

int main()
{
//	freopen("a.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(0);

	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	for (auto &i : a) cin >> i;
	auto b = a;
	sort(b.begin(), b.end());
	b.erase(unique(b.begin(), b.end()), b.end());
	map<int, int> mp;
	for (int i = 0, sz = b.size(); i < sz; ++i)
		mp[b[i]] = i;
	for (auto &i : a) i = mp[i];

	vector<vector<pair<int, int>>> t(174);
	for (int k = 173; k > 1; --k)
	{
		memset(f, 0, sizeof f);
		int p1 = 0, p2 = 1;
		++f[a[0]];
		int cnt = 0;

		while (p1+k <= n)
		{
			while (p2 < n && cnt < k)
			{
				if (++f[a[p2]] == k) ++cnt;
				++p2;
			}

			if (cnt < k) break;

			while (f[a[p1]] != k || cnt > k)
			{
				if (f[a[p1]]-- == k) --cnt;
				++p1;
			}

			t[k].push_back({ p1, p2-1 });

			if (f[a[p1]]-- == k) --cnt;
			++p1;
		}
	}

	for (int x, y; q--; )
	{
		cin >> x >> y;
		--x, --y;
		int ans = 1;
		int b = 2, e = 173;
		while (b < e)
		{
			int k = (b+e+1)>>1;
			auto it = lower_bound(t[k].begin(), t[k].end(), make_pair(x, -1));
			if (it != t[k].end() && it->S <= y)
				b = k;
			else
				e = k-1;
		}
		auto it = lower_bound(t[b].begin(), t[b].end(), make_pair(x, -1));
		if (it != t[b].end() && it->S <= y)
			ans = b;
		cout << ans << "\n";
	}

	return 0;
}
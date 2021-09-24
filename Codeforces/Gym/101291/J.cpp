// Problem name: Postman
// Problem link: https://codeforces.com/gym/101291/problem/J
// Submission link: https://codeforces.com/gym/101291/submission/37241159

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main()
{
	//freopen("a.txt", "r", stdin);
	ios_base::sync_with_stdio(false), cin.tie(NULL);

	ll n, k;
	cin >> n >> k;
	vector<vector<pair<ll, ll>>> x(2);

	ll ans = 0, tx, ty;
	for (int i = 0; i < n; ++i)
	{
		cin >> tx >> ty;
		if (tx < 0)
			x[0].push_back({tx, ty});
		else if (tx > 0)
			x[1].push_back({tx, ty});
	}

	sort(x[0].begin(), x[0].end());
	sort(x[1].begin(), x[1].end());
	reverse(x[0].begin(), x[0].end());

	for (int it = 0; it < 2; ++it)
	{
		for (int p = x[it].size()-1; p >= 0; --p)
		{
			ll z = (x[it][p].second/k);
			x[it][p].second -= z * k;
			ans += z * 2 * abs(x[it][p].first);
			if (x[it][p].second == 0) continue;
			ll cur = k;
			ans += 2 * abs(x[it][p].first);
			for (int i = p; cur > 0 && i >= 0; --i)
			{
				ll temp = min(cur, x[it][i].second);
				x[it][i].second -= temp;
				cur -= temp;
			}
		}
	}

	cout << ans << "\n";

    return 0;
}
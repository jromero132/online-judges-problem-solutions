// Problem name: Round Subset
// Problem link: https://codeforces.com/contest/837/problem/D
// Submission link: https://codeforces.com/contest/837/submission/43745167

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int dp[2][205][26 * 205];

int main()
{
	//freopen("a.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(0);

	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> a(n);

	ll x;
	for (auto &i : a)
	{
		cin >> x;
		i.F = 0;
		while (x % 2 == 0) x /= 2, ++i.F;
		i.S = 0;
		while (x % 5 == 0) x /= 5, ++i.S;
	}

	memset(dp, -1, sizeof dp);
	dp[0][0][0] = 0;
	int to = 26*201;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j <= k; ++j)
			for (int t = 0; t < to; ++t)
				dp[~i&1][j][t] = -1;

		for (int j = 0; j <= k; ++j)
			for (int t = 0; t < to; ++t)
				if (dp[i&1][j][t] != -1)
				{
					dp[~i&1][j+1][t+a[i].S] = max(dp[~i&1][j+1][t+a[i].S], dp[i&1][j][t] + a[i].F);
					dp[~i&1][j][t] = max(dp[~i&1][j][t], dp[i&1][j][t]);
				}
	}

	int ans = 0;
	for (int t = 0; t < to; ++t)
		ans = max(min(dp[n&1][k][t], t), ans);

	cout << ans << "\n";

	return 0;
}
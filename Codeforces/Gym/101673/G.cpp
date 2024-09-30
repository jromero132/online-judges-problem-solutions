// Problem name: A Question of Ingestion
// Problem link: https://codeforces.com/gym/101673/problem/G
// Submission link: https://codeforces.com/gym/101673/submission/37980416

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll dp[105][20010][3];
ll last[105][20010][3];

int main()
{
	//freopen("a.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<ll> a(n);
	for (auto &i : a)
		cin >> i;

	for (int i = 0; i <= 20000; ++i)
		last[0][i][0] = m;

	for (int i = 0; i <= n; ++i)
		for (ll j = 0; j <= 20000; ++j)
			for (int k = 0; k < 3; ++k)
				dp[i][j][k] = numeric_limits<ll>::min();

	dp[0][m][2] = 0;

	for (int i = 0; i < n; ++i)
		for (ll j = 0; j <= 20000; ++j)
		{
			if (dp[i][j][0] + min(j, a[i]) > dp[i+1][j*2/3][0])
			{
				dp[i+1][j*2/3][0] = dp[i][j][0] + min(j, a[i]);
				last[i+1][j*2/3][0] = j;
			}

			dp[i+1][last[i][j][0]][1] = max(dp[i+1][last[i][j][0]][1], dp[i][j][0]);

			if (dp[i][j][1] + min(j, a[i]) > dp[i+1][j*2/3][0])
			{
				dp[i+1][j*2/3][0] = dp[i][j][1] + min(j, a[i]);
				last[i+1][j*2/3][0] = j;
			}

			dp[i+1][m][2] = max(dp[i+1][m][2], dp[i][j][1]);

			if (dp[i][j][2] + min(j, a[i]) > dp[i+1][j*2/3][0])
			{
				dp[i+1][j*2/3][0] = dp[i][j][2] + min(j, a[i]);
				last[i+1][j*2/3][0] = j;
			}

			dp[i+1][m][2] = max(dp[i+1][m][2], dp[i][j][2]);
		}

	ll ans = 0;
	for (int i = 0; i <= 20000; ++i)
		for (int j = 0; j < 3; ++j)
			ans = max(ans, dp[n][i][j]);
	cout << ans << "\n";

	return 0;
}

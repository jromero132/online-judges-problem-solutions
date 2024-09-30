// Problem name: Equality
// Problem link: https://codeforces.com/gym/101291/problem/F
// Submission link: https://codeforces.com/gym/101291/submission/37238767

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int dp[55][258];

int main()
{
	//freopen("a.txt", "r", stdin);
	ios_base::sync_with_stdio(false), cin.tie(NULL);

	/*string s;
	cin >> s;

	auto a = "abcdefghijklmnopqrstuvwxyz";

	memset(dp, 63, sizeof dp);
	dp[0]['a'-1] = 0;
	for (int i = 1; i <= s.length(); ++i)
		for (char j = 'a'; j <= 'z'; ++j)
		{
			dp[i][j] = min(dp[i][j], dp[i-1][j]);
			dp[i][j] = min(dp[i][j], dp[i-1][j-1]+1);
			if (s[i-1] == j)
				dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
		}

	cout << dp[s.length()]['z'] << "\n";*/

	ll a, b, c;
	char d, e;
	cin >> a >> d >> b >> e >> c;
	if (a+b == c)
		cout << "YES\n";
	else
		cout << "NO\n";

    return 0;
}
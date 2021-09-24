// Problem name: Divide by Three
// Problem link: https://codeforces.com/contest/792/problem/C
// Submission link: https://codeforces.com/contest/792/submission/44926216

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define F first
#define S second

struct data
{
	int x, i, j, k;
	char z;
	data() : x(1<<30), z('@') {}
	data(int a, char t, int b, int c, int d)
	{
		x = a, i = b, j = c, k = d;
		z = t;
	}
};

int main()
{
	//freopen("a.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(0);

	string s;
	cin >> s;

	int n = s.length();
	vector<vector<vector<data>>> dp(n+1, vector<vector<data>>(3, vector<data>(2)));
	dp[0][0][0].x = 0;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < 3; ++j)
			for (int k = 0; k < 2; ++k)
				if (dp[i][j][k].x != 1<<30)
				{
					if ((s[i] != '0' || k) && dp[i][j][k].x < dp[i+1][(j+s[i]-'0')%3][1].x)
						dp[i+1][(j+s[i]-'0')%3][1] = { dp[i][j][k].x, s[i], i, j, k };
					if (dp[i][j][k].x+1 < dp[i+1][j][k].x)
						dp[i+1][j][k] = { dp[i][j][k].x+1, '@', i, j, k };
				}

	if (dp[n][0][1].x == 1<<30)
	{
		for (auto i : s)
			if (i == '0')
			{
				cout << i;
				return 0;
			}
		cout << "-1";
		return 0;
	}

	if (dp[n][0][1].x == n)
	{
		cout << "-1";
		return 0;
	}

	string ans = "";
	int i = n, j = 0, k = 1;
	while (i != 0)
	{
		if (dp[i][j][k].z != '@')
			ans += dp[i][j][k].z;
		tie(i, j, k) = { dp[i][j][k].i, dp[i][j][k].j, dp[i][j][k].k };
	}

	//while (ans.back() == '0' && ans.length() > 1) ans.pop_back();

	reverse(ans.begin(), ans.end());
	cout << ans << "\n";

	return 0;
}
// Problem name: Juicy Candies
// Problem link: https://codeforces.com/gym/101522/problem/J
// Submission link: https://codeforces.com/gym/101522/submission/44088342

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

ll dp[202][202][202][3];

int main()
{
	//freopen("a.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(0);

	ll B, R, S, K;
	cin >> B >> R >> S >> K;

	dp[1][0][0][0] = dp[0][1][0][1] = dp[0][0][1][2] = 1;
	for (int i = 0; i <= B; ++i)
		for (int j = 0; j <= R; ++j)
			for (int k = 0; k <= S; ++k)
				for (int l = 0; l < 3; ++l)
					for (int m = 0; m < 3; ++m)
						if (l != m)
						{
							ll &x = dp[i+(m==0)][j+(m==1)][k+(m==2)][m];
							x = min(x+dp[i][j][k][l], K);
						}

	ll s = 0;
	for (int k = 0; k < 3; ++k)
		s += dp[B][R][S][k];

	if (s < K)
	{
		cout << "None\n";
		return 0;
	}

	string ans = "";
	map<char, int> mp = { { 'B', 0 }, { 'R', 1 }, { 'S', 2 } };

	while (B+R+S > 1)
	{
		if (B && (ans.empty() || ans.back() != 'B'))
		{
			s = dp[B][R][S][0];

			if (s >= K)
			{
				ans += "B", --B;
				continue;
			}
			else
				K -= s;
		}

		if (R && (ans.empty() || ans.back() != 'R'))
		{
			s = dp[B][R][S][1];

			if (s >= K)
			{
				ans += "R", --R;
				continue;
			}
			else
				K -= s;
		}

		if (S && (ans.empty() || ans.back() != 'S'))
		{
			s = dp[B][R][S][2];

			if (s >= K)
			{
				ans += "S", --S;
				continue;
			}
			else
				K -= s;
		}
	}

	if (B) ans += "B";
	if (R) ans += "R";
	if (S) ans += "S";

	cout << ans << "\n";

	return 0;
}
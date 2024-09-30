// Problem name: Alphabet
// Problem link: https://codeforces.com/gym/101291/problem/A
// Submission link: https://codeforces.com/gym/101291/submission/37238880

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int dp[55][55];

int main()
{
	//freopen("a.txt", "r", stdin);
	ios_base::sync_with_stdio(false), cin.tie(NULL);

	string s;
	cin >> s;
	auto a = "abcdefghijklmnopqrstuvwxyz";

	int n = s.length();
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= 26; ++j)
		{
			if (s[i-1] != a[j-1])
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			else
				dp[i][j] = dp[i-1][j-1]+1;
		}

	cout << 26 - dp[n][26] << "\n";

    return 0;
}
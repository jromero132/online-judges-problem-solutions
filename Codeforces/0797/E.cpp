// Problem name: Array Queries
// Problem link: https://codeforces.com/contest/797/problem/E
// Submission link: https://codeforces.com/contest/797/submission/44375671

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second



int main()
{
	//freopen("a.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &i : a)
		cin >> i;

	int r = sqrt(n)+1;
	vector<vector<int>> dp(n, vector<int>(r));

	for (int p = n-1; p >= 0; --p)
		for (int k = 1; k < r; ++k)
			dp[p][k] = 1+(((p+a[p]+k) < n) ? dp[p+a[p]+k][k] : 0);

	int q;
	cin >> q;
	while (q--)
	{
		int p, k;
		cin >> p >> k;

		--p;
		if (k >= r)
		{
			int ans = 0;
			while (p < n)
				p += a[p]+k, ++ans;
			cout << ans << "\n";
		}
		else
			cout << dp[p][k] << "\n";
	}


	return 0;
}
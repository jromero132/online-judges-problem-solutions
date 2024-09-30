// Problem name: Travelling Salesman and Special Numbers
// Problem link: https://codeforces.com/contest/914/problem/C
// Submission link: https://codeforces.com/contest/914/submission/44410876

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

ll mem[1005][1005][2];
const ll mod = 1e9+7;

int main()
{
	//freopen("a.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(0);

	string s;
	cin >> s;
	int k;
	cin >> k;

	if (k == 0)
	{
		cout << "1\n";
		return 0;
	}

	if (k > 5)
	{
		cout << "0\n";
		return 0;
	}

	vector<int> dp(1005);
	for (int i = 2; i <= 1000; ++i)
	{
		int b = __builtin_popcount(i);
		if (b == 1)
			dp[i] = 1;
		else
			dp[i] = 1+dp[b];
	}

	int n = s.length();
	memset(mem, -1, sizeof mem);
	function<ll(int, int, int)> calc = [&](int p, int k, bool low)
	{
		if (k < 0)
			return 0LL;

		ll &ans = mem[p][k][low];
		if (p == n)
			return (ans = (k == 0));

		if (ans == -1)
		{
			ans = 0;
			ans += calc(p+1, k, low || s[p] == '1');
			if (low || s[p] == '1')
				ans += calc(p+1, k-1, low);
			ans %= mod;
		}
		return ans;
	};

	ll ans = 0;
	for (int i = 1; i <= 1000; ++i)
	{
		calc(0, i, false);
		if (1+dp[i] == k)
			ans += max(mem[0][i][0], 0LL)+max(mem[0][i][1], 0LL) - (i==1), ans %= mod;
	}

	cout << (ans+mod)%mod << "\n";


	return 0;
}
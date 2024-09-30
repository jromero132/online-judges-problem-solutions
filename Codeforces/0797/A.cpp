// Problem name: k-Factorization
// Problem link: https://codeforces.com/contest/797/problem/A
// Submission link: https://codeforces.com/contest/797/submission/44374693

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

	ll n, k;
	cin >> n >> k;
	vector<int> ans;
	for (int i = 2; i <= n; ++i)
	{
		while (k > 1 && n % i == 0)
			ans.push_back(i), --k, n /= i;
	}

	if (k != 1 || n <= 1)
	{
		cout << "-1";
		return 0;
	}

	ans.push_back(n);
	for (auto &i : ans)
		cout << i << " \n"[&i==&ans.back()];

	return 0;
}
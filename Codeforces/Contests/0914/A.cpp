// Problem name: Perfect Squares
// Problem link: https://codeforces.com/contest/914/problem/A
// Submission link: https://codeforces.com/contest/914/submission/44404971

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
	int ans = -1e9;
	for (auto &i : a)
	{
		cin >> i;
		int x = sqrt(abs(i));
		bool ok = true;
		for (int j = -2; j <= 2; ++j)
		{
			ll k = x+j;
			if (k*k == i)
				ok = false;
		}
		if (ok)
			ans = max(ans, i);
	}

	cout << ans << "\n";

	return 0;
}
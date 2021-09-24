// Problem name: Aesthetics in poetry
// Problem link: https://codeforces.com/gym/101879/problem/B
// Submission link: https://codeforces.com/gym/101879/submission/45336043

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

typedef long long ll;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &i : a ) cin >> i;
	int ans = 1<<30;
	for (int k = 2; k <= n; ++k)
	{
		if (n%k==0)
		{
			int d = n/k;
			vector<int> r(k);
			for (auto i : a)
				++r[i%k];
			bool ok = true;
			for (auto i : r)
				ok &= i==d;
			if (ok) ans = min(ans, k);
		}
	}

	if (ans == 1<<30)
		ans = -1;
	cout << ans;

	return 0;
}
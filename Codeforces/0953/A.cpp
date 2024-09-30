// Problem name: 2-3-numbers
// Problem link: https://codeforces.com/contest/953/problem/A
// Submission link: https://codeforces.com/contest/953/submission/37915329

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


int main()
{
	//freopen("a.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(0);

	ll l, r;
	cin >> l >> r;

	int ans = 0;
	ll x = 1;
	for (; x <= r; x *= 2)
	{
		ll y = 1;
		for (; y <= r; y *= 3)
			if (l <= (long double)x*y && (long double)x*y <= r)
				++ans;
	}

	cout << ans << "\n";

	return 0;
}
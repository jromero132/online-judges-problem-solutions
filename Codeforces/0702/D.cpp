// Problem name: Road to Post Office
// Problem link: https://codeforces.com/contest/702/problem/D
// Submission link: https://codeforces.com/contest/702/submission/45431147

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

	ll d, k, a, b, t;
	cin >> d >> k >> a >> b >> t;

	auto cost = [&](ll m)
	{
		return min(d, (m+1)*k)*a + max(d-(m+1)*k, 0LL)*b + t*m;
	};

	ll l = 0, r = 1e12+2;
	while (l+10 < r)
	{
		ll m1 = l + (r-l)/3, m2 = l + (r-l)*2/3;

		if (cost(m1) > cost(m2))
			l = m1;
		else
			r = m2;
	}

	ll ans = numeric_limits<ll>::max();
	for (; l <= r; ++l)
		ans = min(ans, cost(l));

	cout << ans << "\n";

	return 0;
}
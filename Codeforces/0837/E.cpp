// Problem name: Vasya's Function
// Problem link: https://codeforces.com/contest/837/problem/E
// Submission link: https://codeforces.com/contest/837/submission/43746192

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

	function<vector<ll>(ll)> fac = [](ll a)
	{
		vector<ll> fp;
		for (ll i = 2; i*i <= a; ++i)
			if (a % i == 0)
			{
				fp.push_back(i);
				while (a % i == 0) a /= i;
			}

		if (a > 1)
			fp.push_back(a);

		return fp;
	};

	function<ll(ll, ll)> f = [&](ll a, ll b)
	{
		if (b == 0) return 0LL;

		ll g = __gcd(a, b);
		ll k1 = a/g, k2 = b/g;

		if (--k2 == 0) return 1LL;

		if (__gcd(k1, k2) > 1)
			return 1+f(a, k2*g);

		ll k3 = 0;
		auto fp = fac(k1);
		for (auto i : fp)
			k3 = max(k3, (k2/i) * i);

		return 1+k2-k3 + f(a, k3*g);
	};

	ll x, y;
	cin >> x >> y;
	cout << f(x, y) << "\n";

	return 0;
}
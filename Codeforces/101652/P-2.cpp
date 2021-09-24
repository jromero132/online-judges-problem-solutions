// Problem name: Fear Factoring
// Problem link: https://codeforces.com/gym/101652/problem/P
// Submission link: https://codeforces.com/gym/101652/submission/43589531

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

	const int N = 1e6 + 5;
	vector<int> p(N + 5);
	for (ll i = 3; i <= N; i += 2)
	    if (!p[i])
	        for (ll j = i * i; j <= N; j += 2 * i)
	            p[j] = i;

	for (int i = 4; i <= N; i += 2)
		p[i] = 2;

	ll a, b;
	cin >> a >> b;

	vector<ll> num(b-a+1), ans(b-a+1, 1);
	iota(num.begin(), num.end(), a);

	for (ll i = 2; i < N; ++i)
		if (!p[i])
		{
			ll k = (a+i-1)/i;
			for (ll x = k*i; x <= b; x += i)
			{
				ll &z = num[x-a], s = 1, pr = 1;
				while (z % i == 0) z /= i, pr *= i, s += pr;
				ans[x-a] *= s;
			}
		}

	for (ll x = a; x <= b; ++x)
		if (num[x-a] > 1)
			ans[x-a] *= (1+num[x-a]);

	cout << accumulate(ans.begin(), ans.end(), 0LL) << "\n";

	return 0;
}
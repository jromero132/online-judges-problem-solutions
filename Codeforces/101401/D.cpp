// Problem name: Roads (A)
// Problem link: https://codeforces.com/gym/101401/problem/D
// Submission link: https://codeforces.com/gym/101401/submission/43706097

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
	ll tot = 0;
	vector<ll> a(n);
	for (auto &i : a)
		cin >> i, tot += i;

	vector<ll> b(1, 0);
	for (int i = 0; i < n; ++i)
		b.push_back(b.back() + a[i] * (n-1-i));

	vector<ll> sum(1, 0);
	for (auto i : a)
		sum.push_back(sum.back()+i);

	vector<ll> c(1, 0);
	for (int i = 0; i < n; ++i)
		c.push_back(c.back() + a[n-1-i] * (n-1-i));

	vector<ll> sum2(1, 0);
	for (int i = 0; i < n; ++i)
		sum2.push_back(sum2.back()+a[n-1-i]);

	ll dist = 0, ans = 0;
	for (int i = 0, j = 0; i < n; ++i)
	{
		while (j+1 < n && dist+a[j] < tot-dist-a[j])
			dist += a[j], ++j;

		dist -= a[i];

		ans += b[j-1 + 1] - b[i-1 + 1] - (n-1-j) * (sum[j-1 + 1] - sum[i-1 + 1]);
		if (j != n-1) ans += c[n-1-(j+1) + 1] - (j) * (sum2[n-1-(j+1) + 1]) + sum[i-1 + 1] * (n-1-j);
	}

	cout << ans << "\n";

	return 0;
}
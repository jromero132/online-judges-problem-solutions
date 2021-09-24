// Problem name: Cellular Network
// Problem link: https://codeforces.com/contest/702/problem/C
// Submission link: https://codeforces.com/contest/702/submission/45430708

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

	int n, m;
	cin >> n >> m;
	vector<ll> a(n), b(m);
	for (auto &i : a) cin >> i;
	for (auto &i : b) cin >> i;

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	ll l = -3e9, r = -l;
	while (l < r)
	{
		ll md = (l+r)>>1;

		int p = 0;
		for (int i = 0; i < n && p < m; ++i)
			while (p < m && abs(a[i]-b[p]) > md) ++p;

		if (p == m)
			l = md+1;
		else
			r = md;
	}

	cout << l;

	return 0;
}
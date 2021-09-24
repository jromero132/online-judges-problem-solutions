// Problem name: Barbells
// Problem link: https://codeforces.com/gym/101291/problem/B
// Submission link: https://codeforces.com/gym/101291/submission/37239573

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

ll s[1<<15];

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<ll> a(n), b(m);
	for (auto &i : a)
		cin >> i;
	for (auto &i : b)
		cin >> i;

	for (int i = 0; i < 1<<m; ++i)
	{
		ll t = 0;
		for (int j = 0; j < m; ++j)
			if (i&1<<j)
				t += b[j];
		s[i] = t;
	}

	vector<ll> mp(1, 0);
	for (int i = 0; i < 1<<m; ++i)
		for (int j = i^((1<<m)-1), m = j; j; j = (j-1)&m)
			if (s[i] == s[j])
				mp.push_back(s[i]);

	sort(a.begin(), a.end());
	a.erase(unique(a.begin(), a.end()), a.end());
	sort(mp.begin(), mp.end());
	mp.erase(unique(mp.begin(), mp.end()), mp.end());

	vector<ll> ans;
	for (auto i : a)
		for (auto j : mp)
			ans.push_back(i+2*j);

	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());
	for (auto i : ans)
		cout << i << "\n";

    return 0;
}
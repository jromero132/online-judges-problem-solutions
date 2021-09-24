// Problem name: Color Changing Sofa
// Problem link: https://codeforces.com/gym/101962/problem/B
// Submission link: https://codeforces.com/gym/101962/submission/45147857

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define F first
#define S second



int main()
{
	//freopen("a.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(0);

	string a, b;
	cin >> a >> b;
	int n = a.length(), m = b.length();
	auto rb = b;
	reverse(rb.begin(), rb.end());

	for (auto &i : rb) i -= '0';
	for (auto &i : b) i -= '0';

	int ans = 0;
	for (int i = 0; i+m <= n; ++i)
	{
		vector<char> c(2, '@');
		bool ok = true;
		for (int j = 0; j < m; ++j)
		{
			if (c[b[j]] == '@')
			{
				c[b[j]] = a[i+j];
				continue;
			}
			ok &= c[b[j]] == a[i+j];
		}

		if (ok)
		{
			++ans;
			continue;
		}

		c[0] = c[1] = '@';
		ok = true;
		for (int j = 0; j < m; ++j)
		{
			if (c[rb[j]] == '@')
			{
				c[rb[j]] = a[i+j];
				continue;
			}
			ok &= c[rb[j]] == a[i+j];
		}

		ans += ok;
	}

	cout << ans << "\n";

	return 0;
}
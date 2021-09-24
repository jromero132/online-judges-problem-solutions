// Problem name: Forest (C)
// Problem link: https://codeforces.com/gym/101798/problem/E
// Submission link: https://codeforces.com/gym/101798/submission/43224956

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;



int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &i : a) cin >> i;

	ll ans = 0;
	for (int i = 0; i < n; ++i)
	{
		vector<int> mp(n);
		int mx1 = -1, p1, mx2 = -1, c = 0, mmp = 0;
		for (int j = i; j < n; ++j)
		{
			if (mx1 <= a[j]) ++c, --mp[j];
			else if (mx2 <= a[j]) mmp = max(mmp, ++mp[p1]);

			ans += c+mmp;
			//cout << mx1 << " " << p1 << " " << mx2 << " " << c << " " << mmp << " " << ans << endl;

			if (a[j] > mx1)
			{
				mx2 = mx1;
				mx1 = a[j];
				p1 = j;
			}
			else if (a[j] > mx2)
			{
				mx2 = a[j];
			}
		}
		//cout << endl;
	}

	cout << ans << "\n";

	return 0;
}
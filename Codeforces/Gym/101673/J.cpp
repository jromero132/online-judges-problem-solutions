// Problem name: Workout for a Dumbbell
// Problem link: https://codeforces.com/gym/101673/problem/J
// Submission link: https://codeforces.com/gym/101673/submission/37981951

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;



int main()
{
	//freopen("a.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(0);

	vector<ll> t(10), r(10);
	vector<ll> pt(10), pr(10), ps(10);
	for (int i = 0; i < 10; ++i)
		cin >> t[i] >> r[i];
	for (int i = 0; i < 10; ++i)
		cin >> pt[i] >> pr[i] >> ps[i];

	ll cur = 0;
	for (int k = 0; k < 3; ++k)
		for (int i = 0; i < 10; ++i)
		{
			if (ps[i] <= cur)
			{
				ll x = (cur-ps[i]) % (pt[i]+pr[i]);
				if (x < pt[i])
				{
					cur += pt[i]-x;
					ps[i] = max(cur+t[i], cur+pr[i]);
				}
				else
				{
					ps[i] = max(cur-x+pt[i]+pr[i], cur+t[i]);
				}
			}
			else
			{
				if (cur+t[i] > ps[i])
					ps[i] = cur+t[i];
			}
			cur += t[i]+r[i];
		}

	cout << cur-r[9];

	return 0;
}
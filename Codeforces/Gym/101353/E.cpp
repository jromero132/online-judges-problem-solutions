// Problem name: Just One Swap
// Problem link: https://codeforces.com/gym/101353/problem/E
// Submission link: https://codeforces.com/gym/101353/submission/37261028

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main()
{
	//freopen("a.txt", "r", stdin);
	ios_base::sync_with_stdio(false), cin.tie(NULL);

	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int> a(n);
		for (auto &i : a)
			cin >> i;
		map<int, int> mp;
		for (auto i : a)
			++mp[i];
		ll ans = 0, s = 0, t = 0;
		for (auto i : mp)
		{
			s += i.second;
			if (ans == 0 && i.second > 1) ans = 1;
		}
		for (auto i : mp)
			t += i.second * (s - i.second);
		ans += t/2;
		cout << ans << "\n";
	}

    return 0;
}
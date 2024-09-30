// Problem name: ShaatChara
// Problem link: https://codeforces.com/gym/101353/problem/D
// Submission link: https://codeforces.com/gym/101353/submission/37261382

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
	for (int j = 1; j <= t; ++j)
	{
		int n;
		cin >> n;
		vector<int> a(n);
		int x = 0;
		for (auto &i : a)
			cin >> i, x ^= i;
		int ans = 0;
		for (auto i : a)
			ans += (x^i) < i;
		cout << "Case " << j << ": " << ans << "\n";
	}

    return 0;
}
// Problem name: Two TVs
// Problem link: https://codeforces.com/contest/845/problem/C
// Submission link: https://codeforces.com/contest/845/submission/43050447

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double ld;
#define F first
#define S second


int main()
{
	//freopen("a.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(0);

	int n;
	cin >> n;
	vector<pair<int, int>> e;
	for (int i = 0, x, y; i < n; ++i)
	{
		cin >> x >> y;
		e.push_back({ x, -1 });
		e.push_back({ y, 1 });
	}

	sort(e.begin(), e.end());

	int c = 0;
	for (auto x : e)
	{
		c += -x.S;
		if (c > 2)
		{
			cout << "NO\n";
			return 0;
		}
	}

	cout << "YES\n";

	return 0;
}
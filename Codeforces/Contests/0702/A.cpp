// Problem name: Maximum Increase
// Problem link: https://codeforces.com/contest/702/problem/A
// Submission link: https://codeforces.com/contest/702/submission/45430510

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
	vector<int> a(n);
	for (auto &i : a) cin >> i;

	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		int len = 1;
		while (i+1 < n && a[i+1] > a[i]) ++i, ++len;
		ans = max(ans, len);
	}

	cout << ans << "\n";

	return 0;
}
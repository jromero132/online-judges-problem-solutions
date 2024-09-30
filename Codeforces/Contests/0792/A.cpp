// Problem name: New Bus Route
// Problem link: https://codeforces.com/contest/792/problem/A
// Submission link: https://codeforces.com/contest/792/submission/44925213

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define F first
#define S second



int main()
{
	//freopen("a.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(0);

	int n;
	cin >> n;
	vector<ll> a(n);
	for (auto &i : a)
		cin >> i;

	sort(a.begin(), a.end());
	ll mn = numeric_limits<ll>::max(), cnt;
	for (int i = 0; i < n-1; ++i)
	{
		if (abs(a[i]-a[i+1]) < mn)
			mn = abs(a[i]-a[i+1]), cnt = 1;
		else if (abs(a[i]-a[i+1]) == mn)
			++cnt;
	}

	cout << mn << " " << cnt;

	return 0;
}
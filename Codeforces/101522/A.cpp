// Problem name: Ambiguous Dates
// Problem link: https://codeforces.com/gym/101522/problem/A
// Submission link: https://codeforces.com/gym/101522/submission/44088341

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
	for (auto &i : a)
		cin >> i;
	sort(a.begin(), a.end());

	ll s = 0;
	for (int k = 1; k <= n; ++k)
	{
		int d = a[k-1];
		auto end = a.begin()+min(d-1, n-1)+1;
		auto it = lower_bound(a.begin(), end, k);
		s += end - it;
		if (d >= k) --s;
	}

	cout << s << "\n";

	return 0;
}
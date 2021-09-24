// Problem name: World Mug (B)
// Problem link: https://codeforces.com/gym/101798/problem/G
// Submission link: https://codeforces.com/gym/101798/submission/43222313

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;



int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0);

	int n;
	cin >> n;
	vector<ll> a(n);
	for (auto &i : a) cin >> i;

	ll ans = 0;
	while (a.size() > 1)
	{
		vector<ll> b;
		sort(a.begin(), a.end());
		for (int i = 0, j = a.size()-1; i < j; i++, j--)
			ans += abs(a[i]-a[j]), b.push_back(max(a[i], a[j]));
		a = b;
	}

	cout << ans << "\n";

	return 0;
}
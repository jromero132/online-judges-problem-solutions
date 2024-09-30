// Problem name: World Mug (A)
// Problem link: https://codeforces.com/gym/101798/problem/F
// Submission link: https://codeforces.com/gym/101798/submission/43221942

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
		for (int i = 0; i < a.size(); i += 2)
			ans += abs(a[i]-a[i+1]), b.push_back(max(a[i], a[i+1]));
		a = b;
	}

	cout << ans << "\n";

	return 0;
}
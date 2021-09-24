// Problem name: Almost Identity Permutations
// Problem link: https://codeforces.com/contest/888/problem/D
// Submission link: https://codeforces.com/contest/888/submission/37915845

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


int main()
{
	//freopen("a.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(0);

	ll n, k;
	cin >> n >> k;

	ll ans = 1;
	if (k >= 2)
		ans += n*(n-1)/2;
	if (k >= 3)
		ans += n*(n-1)*(n-2)/(2*3) * 2;
	if (k >= 4)
		ans += n*(n-1)*(n-2)*(n-3)/(2*3*4) * 9;

	cout << ans;

	return 0;
}
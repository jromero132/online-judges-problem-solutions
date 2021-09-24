// Problem name: Star Arrangements
// Problem link: https://codeforces.com/gym/101652/problem/X
// Submission link: https://codeforces.com/gym/101652/submission/43588380

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

	ll n;
	cin >> n;
	cout << n << ":\n";
	for (ll x = 2; x < n; ++x)
		for (ll y = x-1; y <= x; ++y)
		{
			ll k = n/(x+y);
			if (n - k*(x+y) == 0 || n - k*(x+y) - x == 0)
				cout << x << "," << y << "\n";
		}

	return 0;
}
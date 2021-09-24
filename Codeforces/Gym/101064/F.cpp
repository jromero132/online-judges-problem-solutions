// Problem name: Metal detector
// Problem link: https://codeforces.com/gym/101064/problem/F
// Submission link: https://codeforces.com/gym/101064/submission/45256057

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

	int t;
	cin >> t;
	while (t--)
	{
		ll n, x;
		cin >> n >> x;

		ll ans = 0;
		while (true)
		{
			if (x&1)
			{
				cout << ans + (x+1)/2 << "\n";
				break;
			}

			ans += (n+1)/2;
			if (n&1)
				x = x/2-1;
			else
				x = x/2;
			n = n/2;
			if (x <= 0)
				x = n;
		}
	}

	return 0;
}
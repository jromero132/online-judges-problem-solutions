// Problem name: Charm Is Not Always Enough
// Problem link: https://codeforces.com/gym/101353/problem/A
// Submission link: https://codeforces.com/gym/101353/submission/37260768

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
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		ll ans = 0;
		for (int i = 0, x; i < n; ++i)
		{
			cin >> x;
			ans += ((x+m-1) / m) * m - x;
		}
		cout << ans << "\n";
	}

    return 0;
}
// Problem name: Enigma
// Problem link: https://codeforces.com/gym/101908/problem/E
// Submission link: https://codeforces.com/gym/101908/submission/44966296

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define F first
#define S second

string a, b;

int main()
{
	//freopen("a.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(0);

	cin >> a >> b;
	int n = a.length(), m = b.length(), ans = 0;
	for (int i = 0; i+m <= n; ++i)
	{
		++ans;
		for (int j = 0; j < m; ++j)
			if (a[i+j] == b[j])
			{
				--ans;
				break;
			}
	}

	cout << ans << "\n";

	return 0;
}
// Problem name: Gravity
// Problem link: https://codeforces.com/gym/101291/problem/G
// Submission link: https://codeforces.com/gym/101291/submission/37239143

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<string> a(n);
	for (auto &i : a)
		cin >> i;

	for (int j = 0; j < m; ++j)
	{
		string b = "", c = "";
		for (int i = 0; i < n; ++i)
		{
			if (a[i][j] == '#')
			{
				for (auto k : b)
					if (k == '.')
						c += ".";
				for (auto k : b)
					if (k == 'o')
						c += "o";
				c += "#";
				b = "";
				continue;
			}
			b += a[i][j];
		}
		for (auto k : b)
			if (k == '.')
				c += ".";
		for (auto k : b)
			if (k == 'o')
				c += "o";
		for (int i = 0; i < n; ++i)
			a[i][j] = c[i];
	}

	for (int i = 0; i < n; ++i)
		cout << a[i] << "\n";


    return 0;
}
// Problem name: Six Sides
// Problem link: https://codeforces.com/gym/101291/problem/K
// Submission link: https://codeforces.com/gym/101291/submission/37239893

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main()
{
	//freopen("a.txt", "r", stdin);
	ios_base::sync_with_stdio(false), cin.tie(NULL);

	vector<int> a(6), b(6);
	for (auto &i : a)
		cin >> i;
	for (auto &i : b)
		cin >> i;

	int tie = 0, win = 0;
	for (auto i : a)
		for (auto j : b)
		{
			if (i > j)
				++win;
			if (i == j)
				++tie;
		}

	cout.precision(5);
	cout << fixed << (ld)win/(36.0-tie) << "\n";

    return 0;
}
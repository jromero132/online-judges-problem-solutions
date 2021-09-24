// Problem name: Latin Squares
// Problem link: https://codeforces.com/gym/101652/problem/O
// Submission link: https://codeforces.com/gym/101652/submission/43589325

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define get sdjfn

int get[256];

int main()
{
	//freopen("a.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(0);

	memset(get, -1, sizeof get);
	vector<char> ord;
	for (char i = '0'; i <= '9'; ++i)
		get[i] = i-'0', ord.push_back(i);
	for (char i = 'A'; i <= 'Z'; ++i)
		get[i] = i-'A' + 10, ord.push_back(i);

	int n;
	while (cin >> n)
	{
		vector<string> a(n);
		for (auto &i : a)
			cin >> i;

		set<char> mp1, mp2;
		for (int i = 0; i < n; ++i)
		{
			mp1.clear(), mp2.clear();
			for (int j = 0; j < n; ++j)
				mp1.insert(a[i][j]), mp2.insert(a[j][i]);

			if (mp1.size() != n || mp2.size() != n)
			{
				cout << "No\n";
				break;
			}
		}

		if (mp1.size() != n || mp2.size() != n)
			continue;

		bool r = true;
		for (int i = 0; i < n; ++i)
			r &= a[0][i] == ord[i] && a[i][0] == ord[i];

		if (r)
			cout << "Reduced\n";
		else
			cout << "Not Reduced\n";
	}

	return 0;
}
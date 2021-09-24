// Problem name: Odd Palindrome
// Problem link: https://codeforces.com/gym/101652/problem/N
// Submission link: https://codeforces.com/gym/101652/submission/43585709

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

	string s;
	cin >> s;

	int n = s.length();
	bool odd = true;
	for (int i = 0; i < n; ++i)
		for (int j = i+1; j < n; j += 2)
		{
			auto a = s.substr(i, j-i+1);

			bool ok = true;
			for (int k = 0, l = a.length()-1; k < l; ++k, --l)
				ok &= a[k] == a[l];

			if (ok)
				odd = false;
		}

	cout << ((odd)?"Odd.":"Or not.") << "\n";

	return 0;
}
// Problem name: Cheering
// Problem link: https://codeforces.com/gym/101522/problem/C
// Submission link: https://codeforces.com/gym/101522/submission/44080144

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
	vector<int> f(2);
	vector<string> a = {"LSC", "PCMS", };

	int n = s.length();
	for (int k = 0; k < 2; ++k)
		for (int i = 0; i+a[k].size() <= n; ++i)
			f[k] += s.substr(i, a[k].size()) == a[k];

	if (f[0] > f[1])
		cout << a[0];
	else if (f[0] < f[1])
		cout << a[1];
	else
		cout << "Tie";

	return 0;
}
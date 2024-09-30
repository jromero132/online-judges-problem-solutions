// Problem name: Luba And The Ticket
// Problem link: https://codeforces.com/contest/845/problem/B
// Submission link: https://codeforces.com/contest/845/submission/43049928

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double ld;
#define F first
#define S second


int main()
{
	//freopen("a.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(0);

	string s;
	cin >> s;
	vector<int> a;
	for (auto i : s)
		a.push_back(i-'0');

	vector<int> num(6);
	int ans = 1<<30;
	for (int i = 0; i < 1<<24; ++i)
	{
		for (int j = 0; j < 24; j += 4)
			num[j/4] = (i>>j)&((1<<4)-1);
		int s1 = num[0]+num[1]+num[2]-num[3]-num[4]-num[5];
		if (*max_element(num.begin(), num.end()) < 10 && s1 == 0)
		{
			int c = 0;
			for (int j = 0; j < 6; ++j)
				c += a[j] != num[j];
			if (c < ans)
				ans = c;
		}
	}

	cout << ans << "\n";

	return 0;
}
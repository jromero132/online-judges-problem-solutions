// Problem name: DRM Messages
// Problem link: https://codeforces.com/gym/101673/problem/C
// Submission link: https://codeforces.com/gym/101673/submission/37979333

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


int main()
{
	//freopen("a.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(0);

	string s;
	cin >> s;
	string s1 = s.substr(0, s.length()/2), s2 = s.substr(s.length()/2, s.length()/2);
	int r1 = 0;
	for (auto i : s1)
		r1 += i-'A', r1 %= 26;
	int r2 = 0;
	for (auto i : s2)
		r2 += i-'A', r2 %= 26;
	for (int i = 0; i < s.length()/2; ++i)
		cout << (char)((s1[i]+r1+s2[i]+r2-'A'-'A') % 26 + 'A');

	return 0;
}

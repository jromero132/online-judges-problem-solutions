// Problem name: Buggy Robot
// Problem link: https://codeforces.com/contest/888/problem/B
// Submission link: https://codeforces.com/contest/888/submission/37915707

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


int main()
{
	//freopen("a.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(0);

	int n;
	string s;
	cin >> n >> s;
	map<char, int> mp;
	for (auto i : s)
		mp[i]++;

	cout << 2*min(mp['L'], mp['R'])+2*min(mp['D'], mp['U']);

	return 0;
}
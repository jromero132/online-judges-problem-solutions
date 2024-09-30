// Problem name: Chess Tourney
// Problem link: https://codeforces.com/contest/845/problem/A
// Submission link: https://codeforces.com/contest/845/submission/43049979

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

	int n;
	cin >> n;
	vector<int> a(2*n);
	for (auto &i : a)
		cin >> i;

	sort(a.begin(), a.end());

	if (a[n] > a[n-1])
		cout << "YES";
	else
		cout << "NO";

	return 0;
}
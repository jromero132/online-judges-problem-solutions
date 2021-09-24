// Problem name: Group work
// Problem link: https://codeforces.com/gym/101879/problem/E
// Submission link: https://codeforces.com/gym/101879/submission/45335932

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

typedef long long ll;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0);

	int n;
	cin >> n;
	cout << (1LL << n) - n - 1 << endl;
	return 0;
}
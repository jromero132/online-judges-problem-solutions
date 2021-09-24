// Problem name: Bachgold Problem
// Problem link: https://vjudge.net/problem/CodeForces-749A
// Submission link: https://vjudge.net/solution/16113893

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

#ifdef JoseA132
	freopen("01.in", "r", stdin);
#endif

	int n, ans;
	cin >> n;
	cout << (n >> 1) << endl;
	while(n > 3)
		cout << 2 << ' ', n -= 2;
	cout << n << endl;
	return 0;
}
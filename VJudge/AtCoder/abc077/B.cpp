// Problem name: Around Square
// Problem link: https://vjudge.net/problem/AtCoder-abc077_b
// Submission link: https://vjudge.net/solution/32878433

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	int p = sqrt(n);
	cout << p * p;
	return 0;
}
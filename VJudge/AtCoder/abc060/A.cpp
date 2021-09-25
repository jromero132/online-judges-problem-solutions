// Problem name: Shiritori
// Problem link: https://vjudge.net/problem/AtCoder-abc060_a
// Submission link: https://vjudge.net/solution/32878398

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	string a, b, c;
	cin >> a >> b >> c;
	cout << (a[ a.length() - 1 ] == b[ 0 ] && b[ b.length() - 1 ] == c[ 0 ] ? "YES" : "NO");
	return 0;
}
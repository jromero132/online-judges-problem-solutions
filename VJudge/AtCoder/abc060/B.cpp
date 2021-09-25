// Problem name: Choose Integers
// Problem link: https://vjudge.net/problem/AtCoder-abc060_b
// Submission link: https://vjudge.net/solution/32881819

#include <bits/stdc++.h>

using namespace std;

bool solve(int a, int b, int c){
	for(int k = 3 ; k <= b ; ++k)
		if(k * a % b == c)
			return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int a, b, c;
	cin >> a >> b >> c;
	cout << (solve(a, b, c) ? "YES" : "NO");
	return 0;
}
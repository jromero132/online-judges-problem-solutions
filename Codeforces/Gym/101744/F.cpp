// Problem name: MaratonIME attends the lecture (or not)
// Problem link: https://codeforces.com/gym/101744/problem/F
// Submission link: https://codeforces.com/gym/101744/submission/43085513

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);

	int n, m, k, x;
	cin >> n >> m >> k;
	x = (7 * n - 10 * k + 9) / 10;
	if(x < 0)
		x = 0;
	cout << (x <= n - m ? x : -1) << endl;
	cout << (100 * (k + n - m)) / n << endl;
	return 0;
}
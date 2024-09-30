// Problem name: Knights in Chessboard
// Problem link: https://vjudge.net/problem/LightOJ-1010
// Submission link: https://vjudge.net/solution/32878027

#include <bits/stdc++.h>

using namespace std;

int solve(int m, int n){
	if(m == 1 || n == 1)
		return max(m, n);
	if(m > 2 && n > 2)
		return ceil((double)n * m / 2.0);
	return (n * m) / 8 * 4 + min(4, (n * m) % 8);
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	for(int k = 1 ; k <= t ; ++k){
		int m, n;
		cin >> m >> n;
		cout << "Case " << k << ": " << solve(m, n) << endl;
	}
}
// Problem name: Rotation
// Problem link: https://vjudge.net/problem/AtCoder-abc077_a
// Submission link: https://vjudge.net/solution/32878426

#include <bits/stdc++.h>

using namespace std;

bool solve(vector<vector<char>> &grid) {
	int n = grid.size(), m = grid[ 0 ].size();
	for(int i = 0 ; i < n ; ++i)
		for(int j = 0 ; j < m ; ++j)
			if(grid[ i ][ j ] != grid[ n - i - 1 ][ m - j - 1 ])
				return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	const int n = 2, m = 3;
	vector<vector<char>> grid(n, vector<char>(m));
	for(int i = 0 ; i < n ; ++i)
		for(int j = 0 ; j < m ; ++j)
			cin >> grid[ i ][ j ];
	cout << (solve(grid) ? "YES" : "NO");
	return 0;
}
// Problem name: MaratonIME returns home
// Problem link: https://codeforces.com/gym/101744/problem/M
// Submission link: https://codeforces.com/gym/101744/submission/43085136

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<vector<char>> board(n, vector<char>(m));
	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < m ; j++)
			cin >> board[ i ][ j ];
	int dir = 1, best = 0, money = 0;
	for(int i = 0 ; i < n ; i++){
		for(int j = (dir == 1 ? 0 : m - 1) ; j != (dir == 1 ? m : -1) ; j += dir){
			if(board[ i ][ j ] == '.')
				++money;
			else if(board[ i ][ j ] == 'L')
				best = max(best, money), money = 0;
		}
		dir = -dir;
	}
	cout << max(best, money) << endl;
	return 0;
}
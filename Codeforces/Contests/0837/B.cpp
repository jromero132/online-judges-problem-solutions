// Problem name: Flag of Berland
// Problem link: https://codeforces.com/contest/837/problem/B
// Submission link: https://codeforces.com/contest/837/submission/43745307

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);

#ifdef JoseA132
	freopen("01.in", "r", stdin);
#endif

	int n, m;
	cin >> n >> m;
	vector<string> board(n);
	for(auto &s : board)
		cin >> s;
	if(!(n % 3)){
		int l = n / 3;
		bool ok = 1;
		for(int k = 0 ; k < 3 ; ++k){
			for(int i = k * l ; ok && i < (k + 1) * l ; ++i){
				for(int j = 0 ; j < m ; ++j){
					if(board[ i ][ j ] != board[ k * l ][ 0 ]){
						ok = 0;
						break;
					}
				}
			}
		}
		if(ok && board[ 0 ][ 0 ] != board[ l ][ 0 ] && board[ 0 ][ 0 ] != board[ l << 1 ][ 0 ] && board[ l ][ 0 ] != board[ l << 1 ][ 0 ]){
			cout << "YES" << endl;
			return 0;
		}
	}
	if(!(m % 3)){
		int l = m / 3;
		bool ok = 1;
		for(int k = 0 ; k < 3 ; ++k){
			for(int i = k * l ; ok && i < (k + 1) * l ; ++i){
				for(int j = 0 ; j < n ; ++j){
					if(board[ j ][ i ] != board[ 0 ][ k * l ]){
						ok = 0;
						break;
					}
				}
			}
		}
		if(ok && board[ 0 ][ 0 ] != board[ 0 ][ l ] && board[ 0 ][ 0 ] != board[ 0 ][ l << 1 ] && board[ 0 ][ l ] != board[ 0 ][ l << 1 ]){
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}
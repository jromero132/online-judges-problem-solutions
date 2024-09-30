// Problem name: C - Contando caminos
// Problem link: https://matcomgrader.com/problem/9539/contando-caminos/
// Submission link: https://matcomgrader.com/submission/125409/

#include <bits/stdc++.h>

#define MOD ((int)(1e9 + 7))
#define MAX ((int)1e2 + 1)
#define endl '\n'

using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);

	int t, n, r, k;
	for(cin >> t ; t-- ; ){
		cin >> n >> r >> k;
		vector<vector<vector<vector<int>>>> DP(n << 1 | 1, vector<vector<vector<int>>>(n + 1, vector<vector<int>>(r + 1, vector<int>(2, 0))));
		DP[ 0 ][ 0 ][ 0 ][ 0 ] = 1;
		for(int i = 0 ; i < (n << 1) ; i++){
			for(int j = 0 ; j <= n ; j++){
				for(int ii = 0 ; ii <= r ; ii++){
					if(j < n)
						DP[ i + 1 ][ j + 1 ][ ii ][ 0 ] = (DP[ i + 1 ][ j + 1 ][ ii ][ 0 ] + DP[ i ][ j ][ ii ][ 0 ]) % MOD;
					if(j && (ii < r || j != k))
						DP[ i + 1 ][ j - 1 ][ ii + (j == k) ][ 1 ] = (DP[ i + 1 ][ j - 1 ][ ii + (j == k) ][ 1 ] + DP[ i ][ j ][ ii ][ 0 ]) % MOD;
					if(j)
						DP[ i + 1 ][ j - 1 ][ ii ][ 1 ] = (DP[ i + 1 ][ j - 1 ][ ii ][ 1 ] + DP[ i ][ j ][ ii ][ 1 ]) % MOD;
					if(j < n)
						DP[ i + 1 ][ j + 1 ][ ii ][ 0 ] = (DP[ i + 1 ][ j + 1 ][ ii ][ 0 ] + DP[ i ][ j ][ ii ][ 1 ]) % MOD;
				}
			}
		}
		cout << DP[ n << 1 ][ 0 ][ r ][ 1 ] << endl;
	}
	return 0;
}
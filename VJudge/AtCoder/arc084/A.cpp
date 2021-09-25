// Problem name: Snuke Festival
// Problem link: https://vjudge.net/problem/AtCoder-arc084_a
// Submission link: https://vjudge.net/solution/32881958

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	const int m = 3;
	int n;
	cin >> n;
	vector<vector<int>> v(m, vector<int>(n));
	for(auto &x : v){
		for(auto &y : x)
			cin >> y;
		sort(x.begin(), x.end());
	}
	vector<vector<ll>> dp(m, vector<ll>(n + 1));
	for(int i = 0 ; i <= n ; ++i)
		dp[ 0 ][ i ] = i;
	for(int i = 1 ; i < m ; ++i){
		for(int j = 0, left = 0 ; j < n ; ++j){
			while(left < n && v[ i - 1 ][ left ] < v[ i ][ j ])
				++left;
			dp[ i ][ j + 1 ] = dp[ i ][ j ] + dp[ i - 1 ][ left ];
		}
	}
	cout << dp[ 2 ][ n ];
	return 0;
}
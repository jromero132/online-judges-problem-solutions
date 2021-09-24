// Problem name: Maximum Sum
// Problem link: https://vjudge.net/problem/URAL-1146
// Submission link: https://vjudge.net/solution/16889630

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int max_interval_sum(vector<int> &v){
	int ans = INT_MIN, now = 0;
	for(int i = 0, n = v.size() ; i < n ; i++){
		now += v[ i ];
		ans = max(ans, now);
		now = max(now, 0);
	}
	return ans;
}

int max_rectangle_sum(vector<vector<int>> &matrix){
	int ans = INT_MIN;
	for(int i = 0, n = matrix.size(), m = matrix[ 0 ].size() ; i < m ; ++i){
		vector<int> sum(n, 0);
		for(int j = i ; j < m ; j++){
			for(int k = 0 ; k < n ; k++)
				sum[ k ] += matrix[ k ][ j ];
			ans = max(ans, max_interval_sum(sum));
		}
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

#ifdef JoseA132
	freopen("01.in", "r", stdin);
#endif

	int n;
	cin >> n;
	vector<vector<int>> matrix(n, vector<int>(n));
	for(auto &x : matrix)
		for(auto &y : x)
			cin >> y;
	cout << max_rectangle_sum(matrix) << endl;
	return 0;
}
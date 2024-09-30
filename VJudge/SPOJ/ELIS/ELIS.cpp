// Problem name: Easy Longest Increasing Subsequence
// Problem link: https://vjudge.net/problem/SPOJ-ELIS
// Submission link: https://vjudge.net/solution/32984614

#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	vector<int> v(n), ans(n);
	for(int i = 0, cur ; i < n ; ++i){
		cin >> v[ i ];
		ans[ i ] = 1;
		for(int j = 0 ; j < i ; ++j)
			if(v[ j ] < v[ i ])
				ans[ i ] = max(ans[ i ], ans[ j ] + 1);
	}
	cout << *max_element(ans.begin(), ans.end()) << endl;
	return 0;
}
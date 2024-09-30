// Problem name: Hex-a-bonacci
// Problem link: https://vjudge.net/problem/LightOJ-1006
// Submission link: https://vjudge.net/solution/32877759

#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	const int MOD = 10000007;
	int t;
	cin >> t;
	for(int k = 1 ; k <= t ; ++k){
		vector<int> fn(6);
		for(auto &x : fn)
			cin >> x, x %= MOD;
		int n;
		cin >> n;
		for(int r = fn.size() ; fn.size() <= n ; ++r){
			fn.push_back(0);
			for(int l = 1 ; l <= 6 ; ++l)
				fn[ r ] = (fn[ r ] + fn[ r - l ]) % MOD;
		}
		cout << "Case " << k << ": " << fn[ n ] << endl;
	}
}
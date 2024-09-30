// Problem name: Count Subsets
// Problem link: https://vjudge.net/problem/SPOJ-VECTAR5
// Submission link: https://vjudge.net/solution/16560570

#include <bits/stdc++.h>

#define MOD ((int)(1e9 + 7))
#define endl '\n'

using namespace std;

typedef long long ll;

template<typename T1, typename T2, typename T3>
T1 bpow(T1 n, T2 p, T3 m){
	T1 ans = 1;
	for( ; p ; p >>= 1){
		if(p & 1)
			ans = (ans * n) % m;
		n = (n * n) % m;
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);

	int t;
	for(cin >> t ; t-- ; ){
		int n;
		cin >> n;
		cout << ((bpow(2LL, n, MOD) * (bpow(2LL, n, MOD) + 1LL) - 2LL * bpow(3LL, n, MOD)) % MOD + MOD) % MOD << endl;
	}
	return 0;
}
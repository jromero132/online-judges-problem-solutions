// Problem name: D - Tres vecinos
// Problem link: https://matcomgrader.com/problem/9540/tres-vecinos/
// Submission link: https://matcomgrader.com/submission/125413/

#include <bits/stdc++.h>

#define MOD ((ll)(1e9 + 7))
#define endl '\n'

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

vvll multiply(vvll &a, vvll &b){
	vvll mat(a.size(), vll(b[ 0 ].size(), 0));
	int n = a.size(), m = a[ 0 ].size(), o = b[ 0 ].size();
	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < o ; j++)
			for(int k = 0 ; k < m ; k++){
				mat[ i ][ j ] += a[ i ][ k ] * b[ k ][ j ];
				if(mat[ i ][ j ] >= MOD)
					mat[ i ][ j ] %= MOD;
			}
	return mat;
}

vvll pow(vvll &m, ll p){
	int len = m.size();
	vvll ans(len, vll(len, 0));
	for(int i = 0 ; i < len ; ans[ i ][ i ] = 1LL, i++);
	for( ; p ; p >>= 1LL){
		if(p & 1LL)
			ans = multiply(ans, m);
		m = multiply(m, m);
	}
	return ans;
}

ll pow(ll a, ll b){
	ll ans = 1;
	for( ; b ; b >>= 1LL){
		if(b & 1LL){
			ans *= a;
			if(ans >= MOD)
				ans %= MOD;
		}
		a *= a;
		if(a >= MOD)
			a %= MOD;
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	ll n;
	for(cin >> t ; t-- ; ){
		cin >> n;
		vvll ans(4, vll(4, 0LL));
		ans[ 0 ][ 1 ] = ans[ 1 ][ 2 ] = ans[ 2 ][ 0 ] = ans[ 2 ][ 1 ] = ans[ 2 ][ 2 ] = ans[ 2 ][ 3 ] = ans[ 3 ][ 3 ] = 1LL;
		ans = pow(ans, n - 1);
		ll sol = pow(2LL, n), sum = ans[ 0 ][ 0 ] + 3 * ans[ 0 ][ 1 ] + 6 * ans[ 0 ][ 2 ] + 2 * ans[ 0 ][ 3 ];
		sol -= sum + 1;
		if(sol < 0)
			sol = (sol % MOD) + MOD;
		cout << sol << endl;
	}
	return 0;
}
// Problem name: Sum of products
// Problem link: https://vjudge.net/problem/SPOJ-SUMMUL
// Submission link: https://vjudge.net/solution/18136008

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> matrix;

matrix multiply(matrix &a, matrix &b, ll mod){
	int n = a.size(), m = a[ 0 ].size(), o = b[ 0 ].size();
	matrix mat(n, vll(o, 0));
	for(int i = 0 ; i < n ; ++i)
		for(int k = 0 ; k < m ; ++k)
			for(int j = 0 ; j < o ; ++j)
				mat[ i ][ j ] = (mat[ i ][ j ] + a[ i ][ k ] * b[ k ][ j ]) % mod;
	return mat;
}

matrix pow(matrix m, ll p, ll mod){
	int len = m.size();
	matrix ans(len, vll(len, 0));
	for(int i = 0 ; i < len ; ans[ i ][ i ] = 1, ++i);
	for( ; p ; p >>= 1){
		if(p & 1)
			ans = multiply(ans, m, mod);
		m = multiply(m, m, mod);
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

#ifdef JoseA132
	freopen("01.in", "r", stdin);
#endif

	const ll mod = 1000000007;

	int t;
	for(cin >> t ; t-- ; ){
		ll n;
		cin >> n;
		matrix M(2, vll(2, 1));
		M[ 1 ][ 1 ] = 0;
		M = pow(M, n << 1, mod);
		cout << (M[ 0 ][ 1 ]- n + mod) % mod << endl;
	}
	return 0;
}
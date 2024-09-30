// Problem name: Modular Fibonacci
// Problem link: https://vjudge.net/problem/UVA-10229
// Submission link: https://vjudge.net/solution/18073449

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> matrix;

matrix multiply(matrix &a, matrix &b, ll MOD){
	int n = a.size(), m = a[ 0 ].size(), o = b[ 0 ].size();
	matrix mat(n, vll(o, 0LL));
	for(int i = 0 ; i < n ; ++i)
		for(int k = 0 ; k < m ; ++k)
			for(int j = 0 ; j < o ; ++j)
				mat[ i ][ j ] = (mat[ i ][ j ] + a[ i ][ k ] * b[ k ][ j ]) % MOD;
	return mat;
}

matrix pow(matrix m, ll p, ll MOD){
	int len = m.size();
	matrix ans(len, vll(len, 0));
	for(int i = 0 ; i < len ; ans[ i ][ i ] = 1LL, ++i);
	for( ; p ; p >>= 1LL){
		if(p & 1LL)
			ans = multiply(ans, m, MOD);
		m = multiply(m, m, MOD);
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);

#ifdef JoseA132
	freopen("01.in", "r", stdin);
#endif

	ll n, m;
	while(cin >> n >> m){
		matrix M(2, vll(2, 1LL));
		M[ 1 ][ 1 ] = 0LL;
		M = pow(M, n, 1LL << m);
		cout << M[ 0 ][ 1 ] << endl;
	}
	return 0;
}
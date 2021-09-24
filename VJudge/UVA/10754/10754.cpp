// Problem name: Fantastic Sequence
// Problem link: https://vjudge.net/problem/UVA-10754
// Submission link: https://vjudge.net/solution/18143043

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

	int t;
	for(cin >> t ; t-- ; ){
		ll k, m, n;
		cin >> k >> m >> n;

		matrix M(k + 1, vll(k + 1, 0));
		for(int i = 0 ; i <= k ; ++i)
			cin >> M[ 0 ][ i ], M[ 0 ][ i ] = (M[ 0 ][ i ] % m + m) % m;

		for(int i = 1 ; i < k ; ++i)
			M[ i ][ i - 1 ] = 1;

		if(k)
			M[ k ][ k ] = 1;

		matrix F(k + 1, vll(1, 1));
		for(int i = k - 1 ; i >= 0 ; --i)
			cin >> F[ i ][ 0 ], F[ i ][ 0 ] = (F[ i ][ 0 ] % m + m) % m;

		if(n < k)
			cout << F[ k - n - 1 ][ 0 ] << endl;
		else{
			M = pow(M, n - k + 1, m);
			M = multiply(M, F, m);
			cout << M[ 0 ][ 0 ] << endl;
		}

		if(t)
			cout << endl;
	}
	return 0;
}
// Problem name: Summing up Powers
// Problem link: https://vjudge.net/problem/LightOJ-1132
// Submission link: https://vjudge.net/solution/18102836

#include <bits/stdc++.h>

using namespace std;

typedef unsigned int uint;
typedef long long ll;
typedef vector<uint> vui;
typedef vector<vui> matrix;

matrix multiply(matrix &a, matrix &b){
	int n = a.size(), m = a[ 0 ].size(), o = b[ 0 ].size();
	matrix mat(n, vui(o, 0));
	for(int i = 0 ; i < n ; ++i)
		for(int k = 0 ; k < m ; ++k)
			for(int j = 0 ; j < o ; ++j)
				mat[ i ][ j ] += a[ i ][ k ] * b[ k ][ j ];
	return mat;
}

matrix pow(matrix m, ll p){
	int len = m.size();
	matrix ans(len, vui(len, 0));
	for(int i = 0 ; i < len ; ans[ i ][ i ] = 1, ++i);
	for( ; p ; p >>= 1LL){
		if(p & 1LL)
			ans = multiply(ans, m);
		m = multiply(m, m);
	}
	return ans;
}

matrix get_matrix(int k){
	k += 1;
	matrix m(k + 1, vui(k + 1, 0));
	m[ 0 ][ 0 ] = m[ 0 ][ 1 ] = m[ k ][ k ] = 1;
	for(int i = k - 1 ; i ; --i){
		m[ i ][ k ] = 1;
		for(int j = k - 1 ; j ; --j)
			m[ i ][ j ] = m[ i + 1 ][ j ] + m[ i + 1 ][ j + 1 ];
	}
	return m;
}

int main(){
#ifdef JoseA132
	freopen("01.in", "r", stdin);
#endif

	int t;
	scanf("%d", &t);
	for(int c = 1 ; c <= t ; ++c){
		ll n;
		int k;
		scanf("%lld %d", &n, &k);
		matrix M = pow(get_matrix(k), n);
		matrix F(k + 2, vui(1, 1));
		F[ 0 ][ 0 ] = 0;
		M = multiply(M, F);
		printf("Case %d: %lld\n", c, M[ 0 ][ 0 ]);
	}
	return 0;
}
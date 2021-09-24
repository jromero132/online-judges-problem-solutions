// Problem name: Algebraic Problem
// Problem link: https://vjudge.net/problem/LightOJ-1070
// Submission link: https://vjudge.net/solution/18129583

#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef vector<ull> vull;
typedef vector<vull> matrix;

matrix multiply(matrix &a, matrix &b){
	int n = a.size(), m = a[ 0 ].size(), o = b[ 0 ].size();
	matrix mat(n, vull(o, 0));
	for(int i = 0 ; i < n ; ++i)
		for(int k = 0 ; k < m ; ++k)
			for(int j = 0 ; j < o ; ++j)
				mat[ i ][ j ] += a[ i ][ k ] * b[ k ][ j ];
	return mat;
}

matrix pow(matrix m, int p){
	int len = m.size();
	matrix ans(len, vull(len, 0));
	for(int i = 0 ; i < len ; ans[ i ][ i ] = 1, ++i);
	for( ; p ; p >>= 1){
		if(p & 1)
			ans = multiply(ans, m);
		m = multiply(m, m);
	}
	return ans;
}

int main(){
#ifdef JoseA132
	freopen("01.in", "r", stdin);
#endif

	int t;
	scanf("%d", &t);
	for(int k = 1 ; k <= t ; ++k){
		ull p, q, n;
		scanf("%llu%llu%llu", &p, &q, &n);
		if(n == 0)
			printf("Case %d: 2\n", k);
		else{
			matrix M(2, vull(2, 0));
			M[ 0 ][ 0 ] = p;
			M[ 1 ][ 0 ] = q;
			M[ 0 ][ 1 ] = -1;
			matrix F(2, vull(1, 0));
			F[ 0 ][ 0 ] = p, F[ 1 ][ 0 ] = 2 * q;
			M = pow(M, n - 1);
			M = multiply(M, F);
			printf("Case %d: %llu\n", k, M[ 0 ][ 0 ]);
		}
	}
	return 0;
}
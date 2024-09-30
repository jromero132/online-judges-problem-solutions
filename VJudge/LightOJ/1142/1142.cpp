// Problem name: Summing up Powers (II)
// Problem link: https://vjudge.net/problem/LightOJ-1142
// Submission link: https://vjudge.net/solution/18129478

#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> matrix;

matrix multiply(matrix &a, matrix &b, int mod){
	int n = a.size(), m = a[ 0 ].size(), o = b[ 0 ].size();
	matrix mat(n, vi(o, 0));
	for(int i = 0 ; i < n ; ++i)
		for(int k = 0 ; k < m ; ++k)
			for(int j = 0 ; j < o ; ++j)
				mat[ i ][ j ] = (mat[ i ][ j ] + a[ i ][ k ] * b[ k ][ j ]) % mod;
	return mat;
}

matrix pow(matrix m, int p, int mod){
	int len = m.size();
	matrix ans(len, vi(len, 0));
	for(int i = 0 ; i < len ; ans[ i ][ i ] = 1, ++i);
	for( ; p ; p >>= 1){
		if(p & 1)
			ans = multiply(ans, m, mod);
		m = multiply(m, m, mod);
	}
	return ans;
}

int main(){
#ifdef JoseA132
	freopen("01.in", "r", stdin);
#endif

	int t;
	scanf("%d", &t);
	for(int c = 1 ; c <= t ; ++c){
		int n, k;
		scanf("%d %d", &n, &k);
		matrix M(n << 1, vi(n << 1, 0));
		matrix F(n << 1, vi(n, 0));
		for(int i = 0 ; i < n ; ++i)
			for(int j = 0 ; j < n ; ++j)
				scanf("%d", &M[ i ][ j ]), F[ i ][ j ] = M[ i ][ j ];
		for(int i = n ; i < (n << 1) ; ++i)
			M[ i ][ i - n ] = M[ i ][ i ] = 1;
		M = pow(M, k, 10);
		M = multiply(M, F, 10);
		printf("Case %d:\n", c);
		for(int i = 0 ; i < n ; ++i, printf("\n"))
			for(int j = 0 ; j < n ; ++j)
				printf("%d", M[ i + n ][ j ]);
	}
	return 0;
}
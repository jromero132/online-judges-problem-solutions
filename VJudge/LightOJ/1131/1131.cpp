// Problem name: Just Two Functions
// Problem link: https://vjudge.net/problem/LightOJ-1131
// Submission link: https://vjudge.net/solution/18073681

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

typedef vector<int> vi;
typedef vector<vi> matrix;

matrix multiply(matrix &a, matrix &b, int MOD){
	int n = a.size(), m = a[ 0 ].size(), o = b[ 0 ].size();
	matrix mat(n, vi(o, 0LL));
	for(int i = 0 ; i < n ; ++i)
		for(int k = 0 ; k < m ; ++k)
			for(int j = 0 ; j < o ; ++j)
				mat[ i ][ j ] = (mat[ i ][ j ] + a[ i ][ k ] * b[ k ][ j ]) % MOD;
	return mat;
}

matrix pow(matrix m, int p, int MOD){
	int len = m.size();
	matrix ans(len, vi(len, 0));
	for(int i = 0 ; i < len ; ans[ i ][ i ] = 1LL, ++i);
	for( ; p ; p >>= 1LL){
		if(p & 1LL)
			ans = multiply(ans, m, MOD);
		m = multiply(m, m, MOD);
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
		int a1, b1, c1, a2, b2, c2;
		scanf("%d%d%d%d%d%d", &a1, &b1, &c1, &a2, &b2, &c2);
		matrix M(6, vi(6, 0LL));
		M[ 1 ][ 0 ] = M[ 2 ][ 1 ] = M[ 4 ][ 3 ] = M[ 5 ][ 4 ] = 1LL;
		M[ 0 ][ 0 ] = a1, M[ 0 ][ 1 ] = b1, M[ 0 ][ 5 ] = c1;
		M[ 3 ][ 3 ] = a2, M[ 3 ][ 4 ] = b2, M[ 3 ][ 2 ] = c2;


		matrix F(6, vi(1, 0LL));
		for(int i = 0 ; i < 3 ; ++i)
			scanf("%d", &F[ 2 - i ][ 0 ]);
		for(int i = 0 ; i < 3 ; ++i)
			scanf("%d", &F[ 5 - i ][ 0 ]);

		int mod, q, n;
		scanf("%d%d", &mod, &q);
		printf("Case %d:\n", k);
		while(q--){
			scanf("%d", &n);
			if(n < 2)
				printf("%d %d\n", F[ 2 - n ][ 0 ] % mod, F[ 5 - n ][ 0 ] % mod);
			else{
				matrix ans = pow(M, n - 2, mod);
				ans = multiply(ans, F, mod);
				printf("%d %d\n", ans[ 0 ][ 0 ], ans[ 3 ][ 0 ]);
			}
		}
	}
	return 0;
}
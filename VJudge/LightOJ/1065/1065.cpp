// Problem name: Number Sequence
// Problem link: https://vjudge.net/problem/LightOJ-1065
// Submission link: https://vjudge.net/solution/18073729

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
		int a, b, n, d, mod = 1, ans;
		scanf("%d%d%d%d", &a, &b, &n, &d);
		matrix M(2, vi(2, 1LL));
		M[ 1 ][ 1 ] = 0;
		while(d--)
			mod *= 10;
		if(!n)
			ans = a % mod;
		else
			M = pow(M, n - 1, mod), ans = ((b * M[ 0 ][ 0 ]) % mod + (a * M[ 0 ][ 1 ]) % mod) % mod;
		printf("Case %d: %d\n", k, ans);
	}
	return 0;
}
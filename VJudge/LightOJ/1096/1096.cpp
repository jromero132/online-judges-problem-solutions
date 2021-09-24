// Problem name: nth Term
// Problem link: https://vjudge.net/problem/LightOJ-1096
// Submission link: https://vjudge.net/solution/18055403

#include <bits/stdc++.h>

#define pb push_back
#define endl '\n'

using namespace std;

typedef vector<int> vi;
typedef vector<vi> matrix;

matrix multiply(matrix &a, matrix &b, int MOD){
	int n = a.size(), m = a[ 0 ].size(), o = b[ 0 ].size();
	matrix mat(n, vi(o, 0));
	for(int i = 0 ; i < n ; ++i)
		for(int k = 0 ; k < m ; ++k)
			for(int j = 0 ; j < o ; ++j)
				mat[ i ][ j ] = (mat[ i ][ j ] + a[ i ][ k ] * b[ k ][ j ]) % MOD;
	return mat;
}

matrix pow(matrix m, int p, int MOD){
	int len = m.size();
	matrix ans(len, vi(len, 0));
	for(int i = 0 ; i < len ; ans[ i ][ i ] = 1, ++i);
	for( ; p ; p >>= 1){
		if(p & 1)
			ans = multiply(ans, m, MOD);
		m = multiply(m, m, MOD);
	}
	return ans;
}

int main(){
	//ios_base::sync_with_stdio(0), cin.tie(0);

#ifdef JoseA132
	freopen("01.in", "r", stdin);
#endif

	const int mod = 10007;

	int t;
	scanf("%d", &t);
	for(int k = 1 ; k <= t ; ++k){
		int n, a, b, c;
		scanf("%d%d%d%d", &n, &a, &b, &c);
		if(n <= 2){
			printf("Case %d: %d\n", k, 0);
			continue;
		}
		matrix m = { { a, 0, b, 1 }, { 1, 0, 0, 0 }, { 0, 1, 0, 0 }, { 0, 0, 0, 1 } };
		matrix ans =  pow(m, n - 2, mod);
		printf("Case %d: %d\n", k, (ans[ 0 ][ 3 ] * c) % mod);
	}
	return 0;
}
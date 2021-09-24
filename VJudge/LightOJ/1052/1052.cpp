// Problem name: String Growth
// Problem link: https://vjudge.net/problem/LightOJ-1052
// Submission link: https://vjudge.net/solution/18230058

#include <bits/stdc++.h>

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

bool check(ll a1, ll b1, ll x, ll a2, ll b2, ll y, ll A, ll B){
	if(x > y || A < 0 || B < 0)
		return 0;
	if(a1 * A + b1 * B != x || a2 * A + b2 * B != y)
		return 0;
	return 1;
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

#ifdef JoseA132
	freopen("01.in", "r", stdin);
#endif

	const ll mod = 1000000007LL;

	int t;
	scanf("%d", &t);
	for(int c = 1 ; c <= t ; ++c){
		int n, x, m, y, k;
		scanf("%d%d%d%d%d", &n, &x, &m, &y, &k);

		if(n > m)
			swap(n, m), swap(x, y);

		matrix M1(2, vll(2, 1)), M2(2, vll(2, 1)), M3(2, vll(2, 1));
		M1[ 0 ][ 0 ] = M2[ 0 ][ 0 ] = M3[ 0 ][ 0 ] = 0;
		M1 = pow(M1, n, mod);
		M2 = pow(M2, m, mod);
		ll a1 = M1[ 1 ][ 0 ], b1 = M1[ 1 ][ 1 ];
		ll a2 = M2[ 1 ][ 0 ], b2 = M2[ 1 ][ 1 ];

		printf("Case %d: ", c);

		if(!(a1 * b2 - b1 * a2)){
			printf("Impossible\n");
			continue;
		}

		matrix F(2, vll(1, 0));
		F[ 0 ][ 0 ] = (x * b2 - b1 * y) / (a1 * b2 - b1 * a2);
		F[ 1 ][ 0 ] = (a1 * y - x * a2) / (a1 * b2 - b1 * a2);

		if(check(a1, b1, x, a2, b2, y, F[ 0 ][ 0 ], F[ 1 ][ 0 ])){
			M3 = pow(M3, k - 1, mod);
			M3 = multiply(M3, F, mod);
			printf("%d\n", (M3[ 0 ][ 0 ] + M3[ 1 ][ 0 ]) % mod);
		}
		else
			printf("Impossible\n");
	}
	return 0;
}
// Problem name: Discovering Paths in Grid
// Problem link: https://vjudge.net/problem/LightOJ-1160
// Submission link: https://vjudge.net/solution/18143045

#include <bits/stdc++.h>

#define POPCOUNT __builtin_popcount

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

map<int, int> m;

void preprocess(){
	int s = (1 << 4) - 1, p = 0;
	while(!(s & (1 << 7))){
		m[ s ] = p++;
		int lo = s & (~(s - 1));     // lowest one bit
		int lz = (s + lo) & (~s);    // lowest zero bit above lo
		s |= lz;                     // add lz to the set
		s &= (~(lz - 1));            // reset bits below lz
		s |= (lz / lo / 2) - 1;      // put back right number of bits at end. Also (in C) s |= (lz >> ffs(lo)) - 1 to avoid the division.
	}
}

inline bool on(int mask, int i){
	return i != -1 && ((mask >> i) & 1);
}

inline void off(int &mask, int i){
	mask &= ~(1 << i);
}

bool check(int mask1, int mask2){
	for(int i = 0 ; i < 7 ; ++i)
		if((mask1 >> i) & 1)
			off(mask2, on(mask2, i - 1) ? i - 1 : i + 1);
	return !mask2;
}

matrix get_matrix(){
	matrix ans(m.size(), vll(m.size(), 0));
	for(map<int, int>::iterator i = m.begin() ; i != m.end() ; ++i)
		for(map<int, int>::iterator j = m.begin() ; j != m.end() ; ++j)
			ans[ i -> second ][ j -> second ] = check(j -> first, i -> first);
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

#ifdef JoseA132
	freopen("01.in", "r", stdin);
#endif

	preprocess();

	const ll mod = 1000000007;

	int t;
	scanf("%d", &t);
	for(int k = 1 ; k <= t ; ++k){
		int n, p = 0;
		scanf("%d", &n);
		for(int i = 0, x ; i < 7 ; ++i, p <<= 1)
			scanf("%d", &x), p |= (x > 0);
		p >>= 1;
		matrix M = get_matrix(), F(m.size(), vll(1, 0));
		F[ m[ p ] ][ 0 ] = 1;
		M = pow(M, n - 1, mod);
		M = multiply(M, F, mod);
		ll ans = 0;
		for(int i = 0 ; i < M.size() ; ++i)
			ans += M[ i ][ 0 ], ans %= mod;
		printf("Case %d: %lld\n", k, 	ans);
	}
	return 0;
}
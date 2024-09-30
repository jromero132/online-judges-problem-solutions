// Problem name: Decoding Genome
// Problem link: https://vjudge.net/problem/CodeForces-222E
// Submission link: https://vjudge.net/solution/18102832

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
	for(int i = 0 ; i < len ; ans[ i ][ i ] = 1LL, ++i);
	for( ; p ; p >>= 1LL){
		if(p & 1LL)
			ans = multiply(ans, m, mod);
		m = multiply(m, m, mod);
	}
	return ans;
}

int get_pos(char c){
	return islower(c) ? c - 'a' : c - 'A' + 26;
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

#ifdef JoseA132
	freopen("01.in", "r", stdin);
#endif

	const ll mod = 1000000007LL;
	ll n;
	int m, k;
	cin >> n >> m >> k;
	matrix M(m, vll(m, 1LL));
	while(k--){
		char c1, c2;
		cin >> c1 >> c2;
		M[ get_pos(c2) ][ get_pos(c1) ] = 0LL;
	}
	M = pow(M, n - 1, mod);
	int ans = 0;
	for(auto x : M)
		for(auto y : x)
			ans += y, ans %= mod;
	cout << ans << endl;
	return 0;
}
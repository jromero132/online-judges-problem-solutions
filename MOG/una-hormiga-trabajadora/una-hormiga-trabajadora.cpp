// Problem name: E - Una hormiga trabajadora
// Problem link: https://matcomgrader.com/problem/9541/una-hormiga-trabajadora/
// Submission link: https://matcomgrader.com/submission/125414/

#include <bits/stdc++.h>

#define MOD ((ll)(1e9 + 7))
#define MAX ((int)4e5 + 1)
#define endl '\n'

using namespace std;

typedef long long ll;

ll f[ MAX << 1 ];
void preprocess(){
	f[ 0 ] = 1LL;
	for(int i = 1 ; i < (MAX << 1) ; i++)
		f[ i ] = (f[ i - 1 ] * i) % MOD;
}

ll pow(ll a, ll b){
	ll ans = 1;
	for( ; b ; b >>= 1LL){
		if(b & 1LL)
			ans = (ans * a) % MOD;
		a = (a * a) % MOD;
	}
	return ans;
}

ll C(int n, int k){
	return (((f[ n ] * pow(f[ k ], MOD - 2)) % MOD) * pow(f[ n - k ], MOD - 2)) % MOD;
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);

	preprocess();

	int  t, n, m, a, b;
	for(cin >> t ; t-- ; ){
		cin >> n >> m >> a >> b;
		ll ans = 0LL, l = n - a;
		for( ; b <= m ; b++)
			ans += C(l + b, l) * C(a - 1 + m - b, a - 1), ans %= MOD;
		cout << ans << endl;
	}
}
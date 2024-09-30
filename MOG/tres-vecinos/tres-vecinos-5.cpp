// Problem name: D - Tres vecinos
// Problem link: https://matcomgrader.com/problem/9540/tres-vecinos/
// Submission link: https://matcomgrader.com/submission/125349/

#include <bits/stdc++.h>

#define MOD ((ll)(1e9 + 7))
#define pb(x) push_back(x)
//#define endl '\n'

using namespace std;

typedef long long ll;

struct Matrix{
public:
	int n, m;
	vector< vector<ll> > value;

	Matrix() : Matrix(1, 1){ }

	Matrix(int n, int m) : Matrix(vector< vector<ll> >(n, vector<ll>(m, 0))){ }

	Matrix(vector< vector<ll> > a) : n(a.size()), m(a[ 0 ].size()){
		value = vector< vector<ll> >(n, vector<ll>(m, 0));
		for(int i = 0 ; i < n ; i++)
			for(int j = 0 ; j < n ; j++)
				value[ i ][ j ] = a[ i ][ j ];
	}

	void operator = (Matrix a){
		n = a.n;
		m = a.m;
		value = vector< vector<ll> >(n, vector<ll>(m, 0));
		for(int i = 0 ; i < n ; i++)
			for(int j = 0 ; j < n ; j++)
				value[ i ][ j ] = a.value[ i ][ j ];
	}

	Matrix operator * (Matrix a){
		Matrix ans(n, a.m);
		for(int i = 0 ; i < n ; i++)
			for(int j = 0 ; j < a.m ; j++)
				for(int k = 0 ; k < m ; k++)
					ans.value[ i ][ j ] = (ans.value[ i ][ j ] + (value[ i ][ k ] * a.value[ k ][ j ]) % MOD) % MOD;
		return ans;
	}

	void operator *= (Matrix a){
		*this = *this * a;
	}

	Matrix pow(ll p){
		Matrix ans(n, n), a = *this;
		for(int i = 0 ; i < n ; ans.value[ i ][ i ] = 1, i++);
		while(p){
			if(p & 1LL)
				ans *= a;
			a *= a;
			p >>= 1LL;
		}
		return ans;
	}
};

ll pow(ll a, ll b){
	ll ans = 1LL;
	for( ; b ; b >>= 1LL){
		if(b & 1LL)
			ans = (ans * a) % MOD;
		a = (a * a) % MOD;
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	ll n;
	for(cin >> t ; t-- ; ){
		cin >> n;
		Matrix ans(4, 4);
		ans.value[ 0 ][ 0 ] = ans.value[ 0 ][ 2 ] = ans.value[ 0 ][ 3 ] = ans.value[ 1 ][ 0 ] = ans.value[ 1 ][ 1 ] = ans.value[ 1 ][ 3 ] = ans.value[ 3 ][ 0 ] = ans.value[ 3 ][ 1 ] = ans.value[ 3 ][ 2 ] = 0LL;
		ans.value[ 0 ][ 1 ] = ans.value[ 1 ][ 2 ] = ans.value[ 2 ][ 0 ] = ans.value[ 2 ][ 1 ] = ans.value[ 2 ][ 2 ] = ans.value[ 2 ][ 3 ] = ans.value[ 3 ][ 3 ] = 1LL;
		ans = ans.pow(n - 1);
		ll sol = pow(2LL, n), sum = (ans.value[ 0 ][ 0 ] + 3 * ans.value[ 0 ][ 1 ] + 6 * ans.value[ 0 ][ 2 ] + 2 * ans.value[ 0 ][ 3 ]);
		sol = (sol - 1 + MOD) % MOD;
		sol = ((sol - sum) % MOD + MOD) % MOD;
		cout << sol << endl;
	}
	return 0;
}
// Problem name: B - Números k-activos
// Problem link: https://matcomgrader.com/problem/9537/numeros-k-activos/
// Submission link: https://matcomgrader.com/submission/125286/

#include <bits/stdc++.h>

using namespace std;

#define MAX ((int)31)
#define INF ((int)(1 << 30))
#define MOD ((ll)1000000007)
#define pb push_back
#define endl '\n'

typedef long long ll;
typedef pair<ll, int> pli;

ll C[ MAX ][ MAX ];

void preprocess(){
	C[ 0 ][ 0 ] = 1;
	for(int i = 1 ; i < MAX ; i++){
		C[ i ][ 0 ] = C[ i ][ i ] = 1;
		for(int j = 1 ; j < i ; j++)
			C[ i ][ j ] = C[ i - 1 ][ j ] + C[ i - 1 ][ j - 1 ];
	}
}

ll solve(int n, int k, ll m){
	if(m > C[ n ][ k ])
		return -1;
	ll ans = 0;
	for(int i = n - 1 ; i >= 0 && k ; i--){
		if(k == i + 1){
			ans |= (1 << i);
			k--;
			continue;
		}
		if(C[ i ][ k ] >= m)
			continue;
		ans |= (1 << i);
		m -= C[ i ][ k-- ];
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);

	preprocess();

	int t, n, k;
	ll m;
	for(cin >> t ; t-- ; ){
		cin >> n >> k >> m;
		ll ans = solve(n, k, m);
		if(ans < 1 || ans > (1LL << n))
			cout << -1 << endl;
		else{
			for(int i = n - 1 ; i >= 0 ; i--)
				cout << (ans & (1LL << i) ? 1 : 0);
			cout << endl;
		}
	}
}
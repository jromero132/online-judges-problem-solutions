// Problem name: Fafa and Ancient Alphabet
// Problem link: https://codeforces.com/contest/935/problem/D
// Submission link: https://codeforces.com/contest/935/submission/35504187

#include <bits/stdc++.h>

#define MAX ((int)100000)
#define MOD ((ll)1000000007)
#define endl '\n'

using namespace std;

typedef long long ll;

ll Pow(ll a, ll b){
	ll ans = 1LL;
	while(b){
		if(b & 1LL)
			ans = (ans * a) % MOD;
		a = (a * a) % MOD;
		b >>= 1LL;
	}
	return ans;
}

int s1[ MAX ], s2[ MAX ];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m, zeroes = 0;
	cin >> n >> m;
	for(int i = 0 ; i < n ; i++)
		cin >> s1[ i ], zeroes += (s1[ i ] == 0);
	for(int i = 0 ; i < n ; i++)
		cin >> s2[ i ], zeroes += (s2[ i ] == 0);
	ll ans = 0, inv = Pow(Pow(m, zeroes), MOD - 2), f = 1, s = (m * (m - 1LL) / 2LL) % MOD;
	for(int i = 0 ; i < n ; i++){
		if(s1[ i ] != 0 && s2[ i ] != 0){
			if(s1[ i ] < s2[ i ])
				break;
			if(s1[ i ] > s2[ i ]){
				ans = (ans + (f * Pow(m, zeroes)) % MOD) % MOD;
				break;
			}
		}
		else if(s1[ i ] == 0 && s2[ i ] == 0){
			zeroes -= 2;
			ans = (ans + ((f * ((s * Pow(m, zeroes)) % MOD)) % MOD)) % MOD;
			f = (f * m) % MOD;
		}
		else if(s1[ i ] == 0){
			zeroes--;
			ans = (ans + ((f * (((m - s2[ i ]) * Pow(m, zeroes)) % MOD)) % MOD)) % MOD;
		}
		else{
			zeroes--;
			ans = (ans + ((f * (((s1[ i ] - 1) * Pow(m, zeroes)) % MOD)) % MOD)) % MOD;
		}
	}
	cout << ((ans * inv) % MOD) << endl;
	return 0;
}
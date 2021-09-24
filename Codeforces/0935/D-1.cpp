// Problem name: Fafa and Ancient Alphabet
// Problem link: https://codeforces.com/contest/935/problem/D
// Submission link: https://codeforces.com/contest/935/submission/35504418

#include <bits/stdc++.h>

#define MAX ((int)100000)
#define MOD ((ll)1000000007)
#define endl '\n'

using namespace std;

typedef long long ll;

struct terna{
	ll gcd, x, y;
	terna(ll gcd, ll x, ll y) : gcd(gcd), x(x), y(y) {}
};

terna extGcd(ll a, ll b){
	ll x = 0, y = 1, x2 = 1, y2 = 0, temp, q;
	while(b){
		temp = b;
		q = a / b;
		b = a % b;
		a = temp;

		temp = x;
		x = x2 - q * x;
		x2 = temp;

		temp = y;
		y = y2 - q * y;
		y2 = temp;
	}
	return terna(a, x2, y2);
}

ll modInv(ll a, ll m){
	return (extGcd(a, m).x % MOD + MOD) % MOD;
}

ll Pow(ll a, ll b){
	ll ans = 1;
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
	ll ans = 0, inv = modInv(Pow(m, zeroes), MOD), f = 1;
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
			ans = (ans + ((f * (((((ll)m * (m - 1) / 2) % MOD) * Pow(m, zeroes)) % MOD)) % MOD)) % MOD;
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
	cout << (ans * inv) % MOD << endl;
	return 0;
}
// Problem name: E - Desarreglos algo ordenados
// Problem link: https://matcomgrader.com/problem/9241/desarreglos-algo-ordenados/
// Submission link: https://matcomgrader.com/submission/120642/

#include <bits/stdc++.h>

#define MOD (ll)(1e9 + 7)
#define mod(x) (((x) % MOD + MOD) % MOD)

using namespace std;

typedef long long ll;

struct terna{
	ll gcd, x, y;

	terna(ll gcd, ll x, ll y) : gcd(gcd), x(x), y(y){ }
};

terna extGCD(ll a, ll b){
	ll x1 = 0, y1 = 1, x2 = 1, y2 = 0, temp, q;
	while(b){
		temp = b;
		q = a / b;
		b = a % b;
		a = temp;

		temp = x1;
		x1 = x2 - q * x1;
		x2 = temp;

		temp = y1;
		y1 = y2 - q * y1;
		y2 = temp;
	}
	return terna(a, x2, y2);
}

ll modInv(ll a){
	return mod(extGCD(a, MOD).x);
}

ll fact(ll n){
	ll ans = 1;
	for(ll i = 2 ; i <= n ; ans = mod(ans * i++));
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll n, k, bin, ans, now;
	cin >> n >> k;
	ans = now = fact(n);
	bin = k;
	k = min(k, n);
	for(int i = 1 ; i <= k ; i++){
		now = mod(now * modInv(n - i + 1));
		ans = mod(ans + (i & 1 ? -1 : 1) * mod(bin * now));
		bin = mod(bin * mod((k - i) * modInv(i + 1)));
	}
	cout << ans << endl;
    return 0;
}
// Problem name: D - Luces a encender
// Problem link: https://matcomgrader.com/problem/9240/luces-a-encender/
// Submission link: https://matcomgrader.com/submission/120641/

#include <bits/stdc++.h>

#define MAX (int)(1e3 + 1)
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

bool light[ MAX ];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll n, m, x, y, q, ans, now, aux;
	cin >> n >> m;
	ans = fact(n - m);
	while(m--)
		cin >> x, light[ --x ] = 1;
	x = 0;
	for( ; !light[ x ] ; x++);
	ans = mod(ans * modInv(fact(x)));
	for(y = n - 1 ; !light[ y ] ; y--);
	ans = mod(ans * modInv(fact(n - y - 1)));
	q = now = aux = 1;
	while(++x <= y){
		if(light[ x ]){
			ans = mod(mod(ans * modInv(q)) * aux);
			q = now = aux = 1;
			continue;
		}
		q = mod(q * now++);
		if(now != 2)
			aux = mod(aux * 2);
	}
	cout << ans << endl;
    return 0;
}
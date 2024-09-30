// Problem name: D - Luces a encender
// Problem link: https://matcomgrader.com/problem/9240/luces-a-encender/
// Submission link: https://matcomgrader.com/submission/124104/

#include <bits/stdc++.h>

#define MAX (int)(1e3 + 1)
#define MOD (ll)(1e9 + 7)
#define mod(x) (((x) % MOD + MOD) % MOD)

using namespace std;

typedef long long ll;

ll binary_pow(ll a, ll n){
    ll ans = 1LL;
    for( ; n ; n >>= 1LL){
        if(n & 1)
            ans = mod(ans * a);
        a = mod(a * a);
    }
    return ans;
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
	ans = mod(ans * binary_pow(fact(x), MOD - 2));
	for(y = n - 1 ; !light[ y ] ; y--);
	ans = mod(ans * binary_pow(fact(n - y - 1), MOD - 2));
	q = now = aux = 1;
	while(++x <= y){
		if(light[ x ]){
			ans = mod(mod(ans * binary_pow(q, MOD - 2)) * aux);
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
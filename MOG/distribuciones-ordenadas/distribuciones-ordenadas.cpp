// Problem name: B - Distribuciones Ordenadas
// Problem link: https://matcomgrader.com/problem/9238/distribuciones-ordenadas/
// Submission link: https://matcomgrader.com/submission/120635/

#include <bits/stdc++.h>

#define MOD (int)(1e9 + 7)
#define mod(x) (((x) % MOD + MOD) % MOD)
#define endl '\n'

using namespace std;

typedef long long ll;

struct terna{
    ll gcd, x, y;

    terna(ll gcd, ll x, ll y) : gcd(gcd), x(x), y(y){ }
};

terna extGCD(ll a, ll b){
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

ll modInv(ll a){
    return  mod(extGCD(a, MOD).x);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    int n;
    cin >> n;
    ll num = 1, den = 1, ans;
    for(int i = 2 ; i <= n ; den = mod(den * i++));
    for(int i = n ; i <= (n << 1) - 1 ; num = mod(num * i++));
    ans = mod(num * modInv(den));
    cout << mod(mod(2 * ans) - n) << endl;
	return 0;
}
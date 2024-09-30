// Problem name: Divisions
// Problem link: https://codeforces.com/gym/100753/problem/F
// Submission link: https://codeforces.com/gym/100753/submission/20998609

#include <iostream>
#include <math.h>

#define MAX (int)(1e6 + 1)
#define MAXP 25
using namespace std;

typedef long long ll;

int primes[ MAX ];

void sieve(){
    primes[ 0 ] = primes[ 1 ] = 1;
    for(int i = 4 ; i < MAX ; i += 2)
        primes[ i ] = 1;
    for(int i = 3 ; i < MAX ; i += 2)
        if(!primes[ i ])
            for(int j = 3 * i ; j < MAX ; j += 2 * i)
                primes[ j ] = 1;
}

ll mul(ll a, ll b, ll m){
    if(!b)
        return 0;
    ll ret = 2 * mul(a, b / 2, m) % m;
    if(b % 2)
        ret = (ret + a) % m;
    return ret;
}

ll power(ll x, ll n, ll m){
    ll ret = 1;
    for( ; n ; x = mul(x, x, m), n /= 2)
        if( n % 2 )
            ret = mul(ret, x, m);
    return ret;
}

bool rabin_miller(ll p){
    if(p < 2 || ( p > 2 && !( p % 2 )))
        return false;
    for(ll i = 2, t = 0 ; t < MAXP && i < p ; i++)
        if(!primes[ i ]){
            t++;
            if(power(i, p - 1, p) != 1)
                return false;
        }
    return true;
}

int main()
{
    ll n, p, ans = 1, t;
    cin >> n;
    sieve();
    for(ll i = 2 ; i < MAX && i * i * i <= n ; i++)
        if(!primes[ i ]){
            t = 0;
            p = n / i;
            while(n % i == 0)
                n /= i, t++;
            ans *= (t + 1);
        }
    if(n == 1)
        cout << ans << endl;
    else if(rabin_miller(n))
         cout << 2 * ans << endl;
    else
        p = sqrt(n), cout << ans * (p * p == n ? 3 : 4) << endl;
    //system("pause");
    return 0;
}
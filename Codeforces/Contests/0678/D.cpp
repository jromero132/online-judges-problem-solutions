// Problem name: Iterated Linear Function
// Problem link: https://codeforces.com/contest/678/problem/D
// Submission link: https://codeforces.com/contest/678/submission/25028518

#include <iostream>
#include <string.h>

#define MOD (ll)(1e9 + 7)
#define MAX (int)(2)

using namespace std;

typedef long long ll;

ll a, b, n, x, T[ MAX ][ MAX ] = { { 0, 0 }, { 0, 1 } }, F[ MAX ] = { 0, 1 };

ll mul(){
    ll ans[ MAX ];
    for(int i = 0 ; i < MAX ; i++){
        ans[ i ] = 0;
        for(int j = 0 ; j < MAX ; j++){
            ans[ i ] = (ans[ i ] + (T[ i ][ j ] * F[ j ]) % MOD) % MOD;
        }
    }
    for(int i = 0 ; i < MAX ; i++)
        F[ i ] = ans[ i ];
}

ll mul(ll x[ MAX ][ MAX ], ll y[ MAX ][ MAX ]){
    ll ans[ MAX ][ MAX ];
    for(int i = 0 ; i < MAX ; i++)
        for(int j = 0 ; j < MAX ; j++){
            ans[ i ][ j ] = 0;
            for(int k = 0 ; k < MAX ; k++)
                ans[ i ][ j ] = (ans[ i ][ j ] + (x[ i ][ k ] * y[ k ][ j ]) % MOD) % MOD;
        }
    for(int i = 0 ; i < MAX ; i++)
        for(int j = 0 ; j < MAX ; j++)
            x[ i ][ j ] = ans[ i ][ j ];
}

void pow(ll n){
    if(!n)
        return;
    ll ans[ MAX ][ MAX ] = { { 1, 0 }, { 0, 1 } };
    while(n){
        if(n & 1)
            mul(ans, T);
        mul(T, T);
        n >>= 1;
    }
    for(int i = 0 ; i < MAX ; i++)
        for(int j = 0 ; j < MAX ; j++)
            T[ i ][ j ] = ans[ i ][ j ];
}

ll solve(){
    T[ 0 ][ 0 ] = a;
    T[ 0 ][ 1 ] = b;
    F[ 0 ] = x;

    pow(n);
    mul();
    return F[ 0 ];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b >> n >> x;
    cout << solve() << endl;
    return 0;
}
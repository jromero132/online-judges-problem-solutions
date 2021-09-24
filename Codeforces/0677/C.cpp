// Problem name: Vanya and Label
// Problem link: https://codeforces.com/contest/677/problem/C
// Submission link: https://codeforces.com/contest/677/submission/25083762

#include <bits/stdc++.h>

#define MOD (int)(1e9 + 7)

using namespace std;

typedef long long ll;

string s;
ll ans = 1;

int character(char c){
    if(c >= 48 && c <= 57)
        return c - 48;
    if(c >= 65 && c <= 90)
        return c - 55;
    if(c >= 97 && c <= 122)
        return c - 61;
    return c == '-' ? 62 : 63;
}

int bitsZero(int n){
    int res = 0;
    for(int i = 0 ; i < 6 ; i++)
        res += !(n & (1 << i));
    return res;
}

ll power(ll a, ll b){
    ll res = 1;
    while(b){
        if(b & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;
    for(int i = 0 ; s[ i ] != '\0' ; i++)
        ans = ((power(3, bitsZero(character(s[ i ])))) * ans) % MOD;
    cout << ans;
    return 0;
}
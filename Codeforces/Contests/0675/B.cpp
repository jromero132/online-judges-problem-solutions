// Problem name: Restoring Painting
// Problem link: https://codeforces.com/contest/675/problem/B
// Submission link: https://codeforces.com/contest/675/submission/25080204

#include <iostream>

using namespace std;

typedef long long ll;

ll ans = 0, n, a, b, c, d;

bool check(ll x1){
    ll x2 = x1 + b - c;
    if(x2 <= 0 || x2 > n)
        return 0;
    ll x4 = x1 + a - d;
    if(x4 <= 0 || x4 > n)
        return 0;
    ll x5 = x1 + a + b - c - d;
    if(x5 <= 0 || x5 > n)
        return 0;
    return (a + x2 + c == b + x4 + d && a + x2 == d + x5 && b + x4 == c + x5);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> a >> b >> c >> d;
    for(ll i = 1 ; i <= n ; i++)
        ans += check(i);
    cout << ans * n;
    return 0;
}
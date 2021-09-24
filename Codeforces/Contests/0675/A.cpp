// Problem name: Infinite Sequence
// Problem link: https://codeforces.com/contest/675/problem/A
// Submission link: https://codeforces.com/contest/675/submission/25079517

#include <iostream>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll a, b, c, r, k;
    cin >> a >> b >> c;
    if(!c)
        r = 0, k = (a == b ? 1 : -1);
    else
        r = (b - a) % c, k = (b - a) / c;
    //cout << r << endl;
    cout << ((!r && k >= 0) ? "YES" : "NO");
    return 0;
}
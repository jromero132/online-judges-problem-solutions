// Problem name: Joty and Chocolate
// Problem link: https://codeforces.com/contest/678/problem/C
// Submission link: https://codeforces.com/contest/678/submission/25027924

#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, a, b, p, q;
    cin >> n >> a >> b >> p >> q;
    cout << (n / a) * p + (n / b) * q - (n / ((a / __gcd(a, b)) * b)) * min(p, q) << endl;
    return 0;
}
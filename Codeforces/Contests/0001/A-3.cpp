// Problem name: Theatre Square
// Problem link: https://codeforces.com/contest/1/problem/A
// Submission link: https://codeforces.com/contest/1/submission/20929639

#include <iostream>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, m, a;
    cin >> n >> m >> a;
    cout << ((n + a - 1) / a) * ((m + a - 1) / a) << endl;
    return 0;
}
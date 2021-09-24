// Problem name: Theatre Square
// Problem link: https://codeforces.com/contest/1/problem/A
// Submission link: https://codeforces.com/contest/1/submission/27364092

#include <iostream>
#include <math.h>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, m, a;
    cin >> n >> m >> a;
    cout << (ll)(ceil((double)n / a) * ceil((double)m / a));
    return 0;
}
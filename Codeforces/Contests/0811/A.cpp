// Problem name: Vladik and Courtesy
// Problem link: https://codeforces.com/contest/811/problem/A
// Submission link: https://codeforces.com/contest/811/submission/27391028

#include <iostream>
#include <math.h>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll a, b, c, d;
    cin >> a >> b;
    c = sqrt(a);
    d = (sqrt(1 + b << 2) - 1) / 2;
    cout << (c <= d ? "Vladik" : "Valera");
    return 0;
}
// Problem name: New Year Table
// Problem link: https://codeforces.com/contest/140/problem/A
// Submission link: https://codeforces.com/contest/140/submission/25201654

#include <bits/stdc++.h>

#define pi (double)(2 * acos(0))
#define eps (double)(1e-7)

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    double n, R, r;
    cin >> n >> R >> r;
    if(r > R)
        cout << "NO";
    else if(n <= 2)
        cout << (n * r <= R ? "YES" : "NO");
    else{
        double a = 2 * (R - r) * sin(pi / n);
        cout << (a + eps < 2 * r ? "NO" : "YES");
    }
    return 0;
}
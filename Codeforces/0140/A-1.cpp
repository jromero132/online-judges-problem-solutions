// Problem name: New Year Table
// Problem link: https://codeforces.com/contest/140/problem/A
// Submission link: https://codeforces.com/contest/140/submission/25201699

#include <bits/stdc++.h>

#define pi (double)(2 * acos(0))

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
    else if(n == 1)
        cout << (r <= R ? "YES" : "NO");
    else{
        double alpha = acos(r / (R - r)), beta = pi - 2 * alpha;
        cout << (2 * pi / beta >= n ? "YES" : "NO");
    }
    return 0;
}
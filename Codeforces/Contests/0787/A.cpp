// Problem name: The Monster
// Problem link: https://codeforces.com/contest/787/problem/A
// Submission link: https://codeforces.com/contest/787/submission/25754277

#include <bits/stdc++.h>

#define MAX (int)(1e4 + 1)

using namespace std;

int a, b, c, d, t[ MAX ];

int solve(){
    for(int i = b ; i < MAX ; i += a)
        t[ i ] = 1;
    for(int i = d ; i < MAX ; i += c)
        if(t[ i ])
            return i;
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b >> c >> d;
    cout << solve();
    return 0;
}
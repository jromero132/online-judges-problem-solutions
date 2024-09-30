// Problem name: Number of Ways
// Problem link: https://codeforces.com/contest/466/problem/C
// Submission link: https://codeforces.com/contest/466/submission/20929347

#include <iostream>

#define MAX (int)(5e5 + 5)

using namespace std;

typedef long long ll;

ll DP[ MAX ];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, a;
    ll ans = 0, reg = 0, one, two;
    cin >> n;
    for(int i = 1 ; i <= n ; i++)
        cin >> a, DP[ i ] = DP[ i - 1 ] + a;
    if(!(DP[ n ] % 3)){
        one = DP[ n ] / 3;
        two = 2 * one;
        for(int i = 1 ; i < n ; i++){
            if(DP[ i ] == two)
                ans += reg;
            if(DP[ i ] == one)
                reg++;
        }
    }
    cout << ans << endl;
    return 0;
}
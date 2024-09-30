// Problem name: C - Counting substhreengs
// Problem link: https://matcomgrader.com/problem/9305/counting-substhreengs/
// Submission link: https://matcomgrader.com/submission/121263/

#include <bits/stdc++.h>

#define MAX (int)(1e6 + 3)

using namespace std;

typedef long long ll;

ll DP[ MAX ][ 3 ];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string s;
    cin >> s;
    ll ans = 0;
    int mod = 0, i;
    for(i = 0 ; s[ i ] != '\0' ; i++){
        if(s[ i ] < 48 || s[ i ] > 57){
            continue;
        }
        mod = s[ i ] % 3;
        for(int j = 0 ; j < 3 ; j++)
            DP[ i + 1 ][ j ] = DP[ i ][ (j - mod + 3) % 3 ];
        DP[ i + 1 ][ mod ]++;
        ans += DP[ i + 1 ][ 0 ];
    }
    cout << ans;
    return 0;
}
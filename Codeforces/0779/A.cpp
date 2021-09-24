// Problem name: Pupils Redistribution
// Problem link: https://codeforces.com/contest/779/problem/A
// Submission link: https://codeforces.com/contest/779/submission/25062533

#include <iostream>
#include <algorithm>

#define MAX (int)(1e2 + 3)
#define MAX_LENGTH (int)(8)

using namespace std;

int n, group1[ MAX ], group2[ MAX ], total1[ MAX_LENGTH ], total2[ MAX_LENGTH ];

int solve(){
    int aux = 0, ans = 0, now;
    for(int i = 0 ; i < MAX_LENGTH ; i++){
        now = total1[ i ] - total2[ i ];
        if(now & 1)
            return -1;
        aux += now;
        ans += abs(now) / 2;
    }
    return !aux ? ans / 2 : -1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 0 ; i < n ; i++)
        cin >> group1[ i ], total1[ group1[ i ] ]++;
    for(int i = 0 ; i < n ; i++)
        cin >> group2[ i ], total2[ group2[ i ] ]++;
    sort(group1, group1 + n);
    sort(group2, group2 + n);
    cout << solve();
    return 0;
}
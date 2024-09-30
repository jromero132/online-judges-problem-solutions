// Problem name: Lecture Sleep
// Problem link: https://codeforces.com/contest/961/problem/B
// Submission link: https://codeforces.com/contest/961/submission/37235170

#include <bits/stdc++.h>

#define MAX ((int)100001)
#define endl '\n'

using namespace std;

int t[ MAX ], mode[ MAX ];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m, ans = 0, sum = 0, now = 0, sol = 0;
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++)
        cin >> t[ i ];
    for(int i = 0 ; i < n ; i++)
        cin >> mode[ i ], ans += (mode[ i ] ? t[ i ] : 0);
    for(int i = 0 ; i < m ; i++)
        sum += (mode[ i ] ? t[ i ] : 0), now += t[ i ];
    sol = max(sol, ans - sum + now);
    for(int i = m ; i < n ; i++){
        sum += (mode[ i ] ? t[ i ] : 0) - (mode[ i - m ] ? t[ i - m ] : 0);
        now += t[ i ] - t[ i - m ];
        sol = max(sol, ans - sum + now);
    }
    cout << sol << endl;
    return 0;
}
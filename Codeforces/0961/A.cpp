// Problem name: Tetris
// Problem link: https://codeforces.com/contest/961/problem/A
// Submission link: https://codeforces.com/contest/961/submission/37235050

#include <bits/stdc++.h>

#define MAX ((int)1001)
#define endl '\n'

using namespace std;

int square[ MAX ], q = 0;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, p, ans = 0;
    cin >> n >> m;
    for(int i = 0 ; i < m ; i++){
        cin >> p;
        if(!square[ p ]){
            q++;
            square[ p ] = 1;
            if(q == n){
                ans++;
                for(int j = 1 ; j <= n ; j++){
                    square[ j ]--;
                    if(!square[ j ])
                        q--;
                }
            }
        }
        else
            square[ p ]++;
    }
    cout << ans << endl;
    return 0;
}
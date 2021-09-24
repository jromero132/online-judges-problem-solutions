// Problem name: Two Coins
// Problem link: https://csacademy.com/contest/archive/task/two-coins/
// Submission link: https://csacademy.com/submission/1407528/

#include <bits/stdc++.h>

#define MAX ((int)21)
#define MOD ((int)1000000007)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define endl '\n'

using namespace std;

bool check[ MAX ];
int coin[ MAX ];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, ans = 0;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> coin[ i ];
        for(int j = 0 ; j < i ; j++){
            if(!check[ coin[ i ] + coin[ j ] ])
                ans++;
            check[ coin[ i ] + coin[ j ] ] = 1;
        }
    }
    cout << ans << endl;
    return 0;
}
// Problem name: Chessboard
// Problem link: https://codeforces.com/contest/961/problem/C
// Submission link: https://codeforces.com/contest/961/submission/37235389

#include <bits/stdc++.h>

#define MAX ((int)101)
#define INF ((int)1000000000)
#define endl '\n'

using namespace std;

struct board{
    char b[ MAX ][ MAX ];
};

board B[ 4 ];

int solve(int *order, int n, int c){
    int ans = 0;
    for(int i = 0 ; i < 4 ; i++)
        for(int j = 0 ; j < n ; j++)
            for(int k = 0 ; k < n ; k++){
                if(B[ order[ i ] ].b[ j ][ k ] - 48 != c)
                    ans++;
                c = (c + 1) % 2;
            }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, ans = INF;
    cin >> n;
    for(int i = 0 ; i < 4 ; i++)
        for(int j = 0 ; j < n ; j++)
            for(int k = 0 ; k < n ; k++)
                cin >> B[ i ].b[ j ][ k ];
    int order[] = { 0, 1, 2, 3 };
    do{
        ans = min(ans, min(solve(order, n, 0), solve(order, n, 1)));
    }while(next_permutation(order, order + 4));
    cout << ans << endl;
    return 0;
}
// Problem name: Gravity
// Problem link: https://codeforces.com/gym/101291/problem/G
// Submission link: https://codeforces.com/gym/101291/submission/37260095

#include <bits/stdc++.h>

#define MAX ((int)50)
#define endl '\n'

using namespace std;

string board[ MAX ];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, p;
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++)
        cin >> board[ i ];
    for(int j = 0 ; j < m ; j++){
        p = n - 1;
        for(int i = n ; --i >= 0 ; ){
            if(board[ i ][ j ] == '#')
                p = i - 1;
            if(board[ i ][ j ] != 'o')
                continue;
            if(p != i)
                board[ p ][ j ] = 'o', board[ i ][ j ] = '.';
            p--;
        }
    }
    for(int i = 0 ; i < n ; i++)
        cout << board[ i ] << endl;
    return 0;
}
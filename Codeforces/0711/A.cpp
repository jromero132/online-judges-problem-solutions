// Problem name: Bus to Udayland
// Problem link: https://codeforces.com/contest/711/problem/A
// Submission link: https://codeforces.com/contest/711/submission/24875745

#include <bits/stdc++.h>

#define MAX (int)(1e3 + 3)
#define endl '\n'

using namespace std;

bool sol = 0;
string seats[ MAX ];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> seats[ i ];
        if(!sol){
            if(seats[ i ][ 0 ] == seats[ i ][ 1 ] && seats[ i ][ 0 ] == 'O')
                seats[ i ][ 0 ] = seats[ i ][ 1 ] = '+', sol = 1;
            else if(seats[ i ][ 3 ] == seats[ i ][ 4 ] && seats[ i ][ 3 ] == 'O')
                seats[ i ][ 3 ] = seats[ i ][ 4 ] = '+', sol = 1;
        }
    }
    cout << (sol ? "YES" : "NO");
    if(sol){
        for(int i = 0 ; i < n ; i++)
            cout << endl << seats[ i ];
    }
    return 0;
}
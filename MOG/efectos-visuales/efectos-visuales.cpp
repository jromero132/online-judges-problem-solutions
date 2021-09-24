// Problem name: B - Efectos visuales
// Problem link: https://matcomgrader.com/problem/9105/efectos-visuales/
// Submission link: https://matcomgrader.com/submission/108906/

#include <iostream>
#include <cstdlib>

//#include <bits/stdc++.h>

#define MAX (int)(1e5 + 5)
//#define endl '\n'

using namespace std;

typedef long long ll;

string ss[ MAX ], ans[ MAX ];

int main()
{
    int n, m;
    cin >> n >> m;
    string s = "+";
    for(int i = 0 ; i < m ; i++)
        s += "-+";
    ans[ 0 ] = ans[ n - 1 ] = s;
    for(int i = 0 ; i < n ; i++){
        ans[ 2 * i + 1 ] = "|";
        if(i > 0)
            ans[ 2 * i ] = "+";
        cin >> ss[ i ];
        for(int j = 0 ; j < m ; j++){
            if(j > 0){
                 if(ss[ i ][ j ] == ss[ i ][ j - 1 ])
                     ans[ 2 * i + 1 ] += "  ";
                 else
                     ans[ 2 * i + 1 ] += " |";
            }
            if(i > 0){
                 if(ss[ i ][ j ] == ss[ i - 1 ][ j ])
                     ans[ 2 * i ] += " +";
                 else
                     ans[ 2 * i ] += "-+";
            }
        }
        ans[ 2 * i + 1 ] += " |";
        cout << ans[ 2 * i ] << endl << ans[ 2 * i + 1 ] << endl;
    }
        cout << s << endl;
    //system("PAUSE");
    return 0;
}
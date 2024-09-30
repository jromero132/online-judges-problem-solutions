// Problem name: F - Ajuste
// Problem link: https://matcomgrader.com/problem/9101/ajuste/
// Submission link: https://matcomgrader.com/submission/108871/

#include <iostream>
#include <cstdlib>

//#include <bits/stdc++.h>

#define MAX (int)(1e6 + 5)

using namespace std;

typedef long long ll;

ll r[ MAX ], c[ MAX ];

int main()
{
    ll n, q, a, s, rr, cc, rrr, ccc;
    cin >> n >> q;
    char t;
    s = n * (n + 1) / 2;
    for(int i = rr = rrr = cc = ccc = 0 ; i < n ; i++)
        r[ i ] = c[ i ] = s + n * (i + 1);
    while(q--){
        cin >> t >> a;
        if(t == 'R'){
            if(!r[ a - 1 ])
                cout << "0" << endl;
            else{
                cout << r[ a - 1 ] - cc - a * ccc << endl;
                rr += a;
                rrr++;
            }                
            r[ a - 1] = 0;
        }
        else{
            if(!c[ a - 1 ])
                cout << "0" << endl;
            else{
                cout << c[ a - 1 ] - rr - a * rrr << endl;
                cc += a;
                ccc++;
            }                
            c[ a - 1] = 0;
        }
    }
    //system("PAUSE");
    return 0;
}
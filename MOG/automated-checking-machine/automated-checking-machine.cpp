// Problem name: A - Automated Checking Machine
// Problem link: https://matcomgrader.com/problem/9301/automated-checking-machine/
// Submission link: https://matcomgrader.com/submission/121254/

#include <bits/stdc++.h>

#define MAX (int)(1e5 + 1)

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    bool check[ 5 ];
    int x, q = 0;
    for(int i = 0 ; i < 5 ; i++)
        cin >> x, check[ i ] = (x == 1), q += check[ i ];
    for(int i = 0 ; i < 5 ; i++){
        cin >> x;
        if(x & check[ i ]){
            cout << 'N';
            return 0;
        }
        q += x;
    }
    cout << (q == 5 ? 'Y' : 'N');
    return 0;
}
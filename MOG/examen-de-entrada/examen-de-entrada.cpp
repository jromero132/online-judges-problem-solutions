// Problem name: E - Examen de entrada
// Problem link: https://matcomgrader.com/problem/9137/examen-de-entrada/
// Submission link: https://matcomgrader.com/submission/109278/

#include <cstdlib>
#include <iostream>
#include <string.h>

#define MAX (int)(1e5 + 1)
#define endl '\n'

using namespace std;

int array[ MAX ];

int abs(int n){
    return n >= 0 ? n : -n;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, p, a, b, max, ans;
    while(cin >> n >> m >> p && n){
        cin >> a;
        max = ans = 0;
        for(int i = 1 ; i < n ; i++){
            cin >> b;
            if(m <= i && i <= p && abs(b - a) >= max)
                max = abs(b - a), ans = i;
            a = b;
        }
        cout << ans << endl;
    }
    //system("PAUSE");
    return 0;
}
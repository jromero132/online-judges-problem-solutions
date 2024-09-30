// Problem name: A and B and Compilation Errors
// Problem link: https://codeforces.com/contest/519/problem/B
// Submission link: https://codeforces.com/contest/519/submission/20929216

#include <iostream>
#include <algorithm>

#define MAX (int)(1e5 + 5)

using namespace std;

int array[ MAX ], aux[ MAX ];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, a = -1, b = 0;
    cin >> n, n--;
    for(int i = 0 ; i <= n ; i++)
        cin >> array[ i ];
    sort(array, array + n + 1);
    for(int i = 0 ; i < n ; i++)
        cin >> aux[ i ];
    sort(aux, aux + n);
    for(int i = 0 ; i < n ; i++)
        if(array[ i ] != aux[ i ]){
            cout << array[ i ] << endl;
            a = array[ i ];
            break;
        }
    if(a == -1){
        a = array[ n ];
        cout << a << endl;
    }
    n--;
    for(int i = 0 ; i < n ; i++)
        cin >> array[ i ];
    sort(array, array + n);
    a = -1;
    for(int i = 0 ; i < n ; i++)
        if(array[ i ] != aux[ i ]){
            cout << aux[ i ] << endl;
            a = aux[ i ];
            break;
        }
    if(a == -1){
        a = aux[ n ];
        cout << a << endl;
    }
    return 0;
}
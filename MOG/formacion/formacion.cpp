// Problem name: A - Formación
// Problem link: https://matcomgrader.com/problem/51/formacion/
// Submission link: https://matcomgrader.com/submission/100193/

#include <iostream>
#include <algorithm>

#define MAX (int)(1e6 + 1)
#define endl '\n'

using namespace std;

int array[ MAX ];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m = MAX, pos;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> array[ i ];
        if(array[ i ] < m)
            m = array[ i ], pos = i;
    }
    cout << pos + 1 << endl;
    sort(array, array + n);
    cout << array[ 0 ];
    for(int i = 1 ; i < n ; i++)
        cout << " " << array[ i ];
    return 0;
}
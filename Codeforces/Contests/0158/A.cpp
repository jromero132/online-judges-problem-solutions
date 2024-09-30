// Problem name: Next Round
// Problem link: https://codeforces.com/contest/158/problem/A
// Submission link: https://codeforces.com/contest/158/submission/20966896

#include <iostream>
#include <algorithm>

#define MAX (int)(5e1 + 5)

using namespace std;

int array[ MAX ];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k, k = n - k;
    for(int i = 0 ; i < n ; i++)
        cin >> array[ i ];
    sort(array, array + n);
    if(array[ k ])
        for( ; k && array[ k - 1 ] == array[ k ] ; k--);
    else
        for( ; k < n && !array[ k ] ; k++);
    cout << n - k << endl;
    return 0;
}
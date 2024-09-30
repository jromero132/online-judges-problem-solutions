// Problem name: C - Concatenation
// Problem link: https://matcomgrader.com/problem/9270/concatenation/
// Submission link: https://matcomgrader.com/submission/120172/

#include <bits/stdc++.h>

#define MAX (int)(2e1 + 6)
#define endl '\n'

using namespace std;

typedef long long ll;

ll array1[ MAX ], array2[ MAX ];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string a, b;
    cin >> a >> b;
    for(int i = 1 ; a[ i ] != '\0' ; array1[ a[ i++ ] - 97 ]++);
    for(int i = 0 ; b[ i + 1 ] != '\0' ; array2[ b[ i++ ] - 97 ]++);
    ll ans = a.length() * b.length();
    for(int i = 0 ; i < MAX ; i++)
        ans -= array1[ i ] * array2[ i ];
    cout << ans << endl;
    return 0;
}
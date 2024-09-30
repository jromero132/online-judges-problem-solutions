// Problem name: J - Frosting on the Cake
// Problem link: https://matcomgrader.com/problem/9497/frosting-on-the-cake/
// Submission link: https://matcomgrader.com/submission/123905/

#include <bits/stdc++.h>

#define MAX ((int)100000)
#define MAX_DIM ((int)2)
#define MAX_COLOR ((int)3)
#define F first
#define S second
#define endl '\n'

using namespace std;

typedef long long ll;

ll A[ MAX ], B[ MAX_COLOR ], ans[ MAX_COLOR ];

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, v;
    cin >> n;
    for(int i = 0 ; i < n ; i++)
        cin >> A[ i ];
    for(int i = 1 ; i <= n ; i++)
        cin >> v, B[ i % MAX_COLOR ] += v;
    for(int i = 1 ; i <= n ; i++)
        for(int j = 0 ; j < MAX_COLOR ; j++)
            ans[ j ] += A[ i - 1 ] * B[ ((j - i) % MAX_COLOR + MAX_COLOR) % MAX_COLOR ];
    cout << ans[ 0 ];
    for(int i = 1 ; i < MAX_COLOR ; i++)
        cout << ' ' << ans[ i ];
    cout << endl;
    return 0;
}
// Problem name: 4 values whose sum is 0
// Problem link: https://vjudge.net/problem/SPOJ-SUMFOUR
// Submission link: https://vjudge.net/solution/12953503

#include <bits/stdc++.h>

#define MAX ((int)4010)
#define pb push_back
#define sqr(x) ((x) * (x))
#define all(x) x.begin(), x.end()
#define endl '\n'

using namespace std;

typedef long long ll;

int array1[ MAX ], array2[ MAX ], array3[ MAX ], array4[ MAX ];
vector<ll> sum1, sum2;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, len, p1 = 0, p2 = 0, now;
    ll ans = 0;
    cin >> n;
    len = sqr(n);
    for(int i = 0 ; i < n ; i++)
        cin >> array1[ i ] >> array2[ i ] >> array3[ i ] >> array4[ i ];
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < n ; j++)
            sum1.pb(array1[ i ] + array2[ j ]);
    sort(all(sum1));
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < n ; j++)
            sum2.pb(array3[ i ] + array4[ j ]);
    sort(all(sum2));
    ll freq1, freq2;
    for(int i = 0 ; i < len ; ){
        freq1 = 1;
        now = sum1[ i++ ];
        while(i < len && now == sum1[ i ]){
            i++;
            freq1++;
        }
        freq2 = upper_bound(all(sum2), -now) - lower_bound(all(sum2), -now);
        ans += freq1 * freq2;
    }
    cout << ans << endl;
    return 0;
}
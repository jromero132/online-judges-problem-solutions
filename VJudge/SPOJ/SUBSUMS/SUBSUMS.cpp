// Problem name: Subset Sums
// Problem link: https://vjudge.net/problem/SPOJ-SUBSUMS
// Submission link: https://vjudge.net/solution/12943351

#include <bits/stdc++.h>

#define MAX ((int)34)
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'

using namespace std;

typedef long long ll;

int num[ MAX ];
vector<ll> left_sum;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, n21, n22, a, b;
    ll ans = 0, now;
    cin >> n >> a >> b;
    n21 = n >> 1;
    n22 = (n + 1) >> 1;
    for(int i = 0 ; i < n ; i++)
        cin >> num[ i ];
    for(int mask = (1 << n21) ; --mask >= 0 ; ){
        now = 0;
        for(int j = 0 ; j < n21 ; j++)
            if(mask & (1 << j))
                now += num[ j ];
        left_sum.pb(now);
    }
    sort(all(left_sum));
    for(int mask = (1 << n22) ; --mask >= 0 ; ){
        now = 0;
        for(int j = 0 ; j < n22 ; j++)
            if(mask & (1 << j))
                now += num[ n21 + j ];
        ans += upper_bound(all(left_sum), b - now) - lower_bound(all(left_sum), a - now);
    }
    cout << ans << endl;
    return 0;
}
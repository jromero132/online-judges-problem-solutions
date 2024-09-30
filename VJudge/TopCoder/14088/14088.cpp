// Problem name: LimitedMemorySeries1
// Problem link: https://vjudge.net/problem/TopCoder-14088
// Submission link: https://vjudge.net/solution/13324510

#include <bits/stdc++.h>

#define SQRT_MAX ((int)32000)
#define MOD ((int)1000000007)

using namespace std;

typedef long long ll;

class LimitedMemorySeries1{
public:
    ll getSum(int n, int x0, int a, int b, vector<int> query){
        int q = query.size(), c1[ SQRT_MAX ], c2[ SQRT_MAX ], p, now, it, x = x0;
        ll ans = 0;
        memset(c1, 0, sizeof(c1));
        for(int i = 0 ; i < n ; i++)
            c1[ x / SQRT_MAX ]++, x = (int)(((ll)x * a + b) % MOD);
        //for(int i = 1 ; i < SQRT_MAX ; i++)
        //    c1[ i ] += c1[ i - 1 ];
        for(int i = 0 ; i < q ; i++){
            //p = upper_bound(c1, c1 + SQRT_MAX, query[ i ]) - c1;
            //pos = query[ i ] - c1[ p - 1 ];
            p = 0;
            now = query[ i ];
            while(now >= c1[ p ])
                now -= c1[ p++ ];
            //cout << p << ' ' << now << endl;
            memset(c2, 0, sizeof(c2));
            x = x0;
            for(int j = 0 ; j < n ; j++){
                if(x / SQRT_MAX == p)
                    c2[ x % SQRT_MAX ]++;
                x = (int)(((ll)x * a + b) % MOD);
            }
            for(int j = 0 ; j < SQRT_MAX ; j++){
                if(c2[ j ] > now){
                    //cout << '\t' << j << endl;
                    ans += p * SQRT_MAX + j;
                    break;
                }
                now -= c2[ j ];
            }
        }
        return ans;
    }
};
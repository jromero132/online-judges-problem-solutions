// Problem name: ZigZag
// Problem link: https://vjudge.net/problem/TopCoder-1259
// Submission link: https://vjudge.net/solution/31737077

#include <bits/stdc++.h>

#define sz(x) (int)(x).size()
#define F0R(i, end) for(int i = 0 ; i < (end) ; ++i)

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

class ZigZag{
public:
    int longestZigZag(vi sequence){
        vvi dp(sz(sequence), vi(2, 1));
        int ans = 0;
        F0R(i, sz(sequence)){
            F0R(j, i){
                if(sequence[ i ] < sequence[ j ])
                    dp[ i ][ 0 ] = max(dp[ i ][ 0 ], dp[ j ][ 1 ] + 1);
                else if(sequence[ i ] > sequence[ j ])
                    dp[ i ][ 1 ] = max(dp[ i ][ 1 ], dp[ j ][ 0 ] + 1);
            }
            ans = max(ans, max(dp[ i ][ 0 ], dp[ i ][ 1 ]));
        }
        return ans;
    }
};
// Problem name: BadNeighbors
// Problem link: https://vjudge.net/problem/TopCoder-2402
// Submission link: https://vjudge.net/solution/31737752

#include <bits/stdc++.h>

#define sz(x) (int)(x).size()
#define FOR(i, begin, end) for(int i = (begin) ; i < (end) ; ++i)

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

class BadNeighbors{
public:
    int maxDonations(vi donations){
        vvi dp(sz(donations) + 1, vi(2, 0));
        int ans = 0;
        dp[ 1 ][ 0 ] = donations[ 0 ];
        FOR(i, 1, sz(donations)){
            dp[ i + 1 ][ 0 ] = max(dp[ i ][ 0 ], dp[ i - 1 ][ 0 ] + donations[ i ]);
            dp[ i + 1 ][ 1 ] = max(dp[ i ][ 1 ], dp[ i - 1 ][ 1 ] + donations[ i ]);
        }
        return max(dp[ sz(donations) - 1 ][ 0 ], dp[ sz(donations) ][ 1 ]);
    }
};
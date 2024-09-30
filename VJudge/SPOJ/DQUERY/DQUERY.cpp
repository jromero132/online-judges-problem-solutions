// Problem name: D-query
// Problem link: https://vjudge.net/problem/SPOJ-DQUERY
// Submission link: https://vjudge.net/solution/13251246

#include <bits/stdc++.h>

#define MAX ((int)30001)
#define MAX_N ((int)1000001)
#define MAX_Q ((int)200001)
#define DAD(x) ((x) >> 1)
#define LEFT(x) ((x) << 1)
#define RIGHT(x) ((x) << 1 | 1)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;

int n, num[ MAX ], tree[ MAX << 1 ], last[ MAX_N ], ans[ MAX_Q ];
piii query[ MAX_Q ];

void Update(int p, int v){
    for(tree[ p += n ] = v ; DAD(p) ; p = DAD(p))
        tree[ DAD(p) ] = tree[ p ] + tree[ p ^ 1 ];
}

int Query(int l, int r){
    int ans = 0;
    for(l += n, r += n ; l < r ; l = DAD(l), r = DAD(r)){
        if(l & 1)
            ans += tree[ l++ ];
        if(r & 1)
            ans += tree[ --r ];
    }
    return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    memset(last, -1, sizeof(last));

	int q, a, b, p = 0;
	cin >> n;
	for(int i = 0 ; i < n ; i++)
        cin >> num[ i ];
	cin >> q;
	for(int i = 0 ; i < q ; i++)
        cin >> query[ i ].F.S >> query[ i ].F.F, query[ i ].F.S--, query[ i ].S = i;
    sort(query, query + q);
    for(int i = 0 ; i < q ; i++){
        for( ; p < query[ i ].F.F ; p++){
            if(last[ num[ p ] ] == -1)
                Update(p, 1);
            else{
                Update(last[ num[ p ] ], 0);
                Update(p, 1);
            }
            last[ num[ p ] ] = p;
        }
        ans[ query[ i ].S ] = Query(query[ i ].F.S, query[ i ].F.F);
    }
    for(int i = 0 ; i < q ; i++)
        cout << ans[ i ] << endl;
	return 0;
}
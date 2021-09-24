// Problem name: Jewelry
// Problem link: https://vjudge.net/problem/TopCoder-1166
// Submission link: https://vjudge.net/solution/31779007

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vl> vvl;

class Jewelry{
public:
	ll howMany(vi values){
		sort(values.begin(), values.end());
		int sum = 0;
		for(int i = 0 ; i < values.size() ; sum += values[ i++ ]);
		vvl dp1(values.size() + 2, vl(sum + 1, 0)), dp2(values.size() + 2, vl(sum + 1, 0)), C(values.size() + 1, vl(values.size() + 1, 0));
		dp1[ 0 ][ 0 ] = dp2[ values.size() + 1 ][ 0 ] = 1;
		for(int i = 0, j = values.size() ; j > 0 ; ++i, --j){
			for(int s = 0 ; s <= sum ; ++s){
				dp1[ i + 1 ][ s ] = dp1[ i ][ s ];
				dp2[ j ][ s ] = dp2[ j + 1 ][ s ];
				if(s >= values[ i ])
					dp1[ i + 1 ][ s ] += dp1[ i ][ s - values[ i ] ];
				if(s >= values[ j - 1 ])
					dp2[ j ][ s ] += dp2[ j + 1 ][ s - values[ j - 1 ] ];
			}
		}
		C[ 0 ][ 0 ] = 1;
		for(int i = 1 ; i <= values.size() ; ++i){
			C[ i ][ 0 ] = 1;
			for(int j = 1 ; j <= i ; ++j)
				C[ i ][ j ] = C[ i - 1 ][ j ] + C[ i - 1 ][ j - 1 ];
		}
		ll ans = 0;
		for(int i = 0, j = 0, k = 0 ; i < values.size() ; ++i){
			if(!k || values[ i ] != values[ j ]){
				j = i;
				for(k = i + 1 ; k < values.size() && values[ k ] == values[ i ] ; ++k);
			}
			for(int s1 = (i - j + 1) * values[ i ], s = s1 ; s <= sum ; ++s)
				ans += C[ k - j ][ i - j + 1 ] * dp1[ j ][ s - s1 ] * dp2[ i + 2 ][ s ];
		}
		return ans;
	}
};
// Problem name: StripePainter
// Problem link: https://vjudge.net/problem/TopCoder-1215
// Submission link: https://vjudge.net/solution/31821773

#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

class StripePainter{
public:
	int minStrokes(string stripes){
		stripes = stripes;
		int len = stripes.length();
		vvi dp(len, vi(len, 1));
		for(int gap = 1 ; gap < len ; ++gap){
			for(int l = 0, r = gap ; r < len ; ++l, ++r){
				dp[ l ][ r ] = dp[ l ][ r - 1 ] + 1;
				for(int k = l ; k < r ; ++k)
					dp[ l ][ r ] = min(dp[ l ][ r ], dp[ l ][ k ] + dp[ k + 1 ][ r ] - (stripes[ l ] == stripes[ r ] || stripes[ k ] == stripes[ k + 1 ]));
			}
		}
		return dp[ 0 ][ len - 1 ];
	}
};
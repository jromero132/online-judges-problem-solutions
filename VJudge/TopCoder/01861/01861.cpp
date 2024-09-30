// Problem name: ShortPalindromes
// Problem link: https://vjudge.net/problem/TopCoder-1861
// Submission link: https://vjudge.net/solution/31830907

#include <bits/stdc++.h>

using namespace std;

class ShortPalindromes{
	string get_min(string s1, string s2){
		if(s1.length() != s2.length())
			return s1.length() < s2.length() ? s1 : s2;
		return s1 < s2 ? s1 : s2;
	}

public:
	string shortest(string base){
		base = '$' + base;
		vector<vector<string>> dp(base.length() + 1, vector<string>(base.length() + 1, ""));
		for(int i = 1 ; i < base.length() ; dp[ i ][ i ] = base[ i ], ++i);
		for(int gap = 2 ; gap < base.length() ; ++gap){
			for(int l = 1, r = gap ; r < base.length() ; ++l, ++r){
				if(base[ l ] == base[ r ])
					dp[ l ][ r ] = base[ l ] + dp[ l + 1 ][ r - 1 ] + base[ r ];
				else{
					string s1 = base[ l ] + dp[ l + 1 ][ r ] + base[ l ];
					string s2 = base[ r ] + dp[ l ][ r - 1 ] + base[ r ];
					dp[ l ][ r ] = get_min(s1, s2);
				}
			}
		}
		return dp[ 1 ][ base.length() - 1 ];
	}
};
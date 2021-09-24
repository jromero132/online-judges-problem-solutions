// Problem name: QuickSums
// Problem link: https://vjudge.net/problem/TopCoder-2829
// Submission link: https://vjudge.net/solution/31829787

#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

class QuickSums{
public:
	int minSums(string numbers, int sum){
		const int INF = 100;
		vvi dp(numbers.length() + 1, vi(sum + 1, INF));
		dp[ 0 ][ 0 ] = -1;
		for(int i = 0 ; i < numbers.length() ; ++i){
			for(int j = i, n = 0, p = 1 ; j >= 0 ; --j, p *= 10){
				n += p * (numbers[ j ] ^ '0');
				if(n > sum)
					break;
				for(int s = n ; s <= sum ; ++s)
					dp[ i + 1 ][ s ] = min(dp[ i + 1 ][ s ], dp[ j ][ s - n ] + 1);
			}
		}
		return dp[ numbers.length() ][ sum ] == INF ? -1 : dp[ numbers.length() ][ sum ];
	}
};
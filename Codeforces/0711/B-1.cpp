// Problem name: Chris and Magic Square
// Problem link: https://codeforces.com/contest/711/problem/B
// Submission link: https://codeforces.com/contest/711/submission/24877970

#include <bits/stdc++.h>

#define MAX (int)(1e3 + 1)
#define endl '\n'

using namespace std;

typedef long long ll;

int n, x, y;
ll grid[ MAX ][ MAX ], row[ MAX ], col[ MAX ], diagonal1 = 0, diagonal2 = 0;

ll solve(){
    if(n == 1)
		return 1;
	ll sum1 = row[ (x + 1) % n ], sum2 = col[ (y + 1) % n ];
	for(int i = 0; i < n; i++)
		if((i != x && row[ i ] != sum1) || (i != y && col[ i ] != sum2))
            return -1;
	if(sum1 != sum2)
	    return -1;
	if(x != y)
        if(diagonal1 != sum1)
	        return -1;
	if(x != n - y - 1)
        if(diagonal2 != sum1)
    	    return -1;
	if(x == y && diagonal1 != row[ x ])
    	return -1;
	if(x == n - y - 1 && diagonal2 != col[ y ])
    	return -1;
	ll ans = sum1 - row[ x ];
    return ans > 0 ? ans : -1;
}

int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    
	cin >> n;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			cin >> grid[ i ][ j ];
			if(grid[ i ][ j ] == 0)
				x = i, y = j;
			row[ i ] += grid[ i ][ j ];
			col[ j ] += grid[ i ][ j ];
			if(i == j)
				diagonal1 += grid[ i ][ j ];
			if(i == n - j - 1)
				diagonal2 += grid[ i ][ j ];
		}
	}
	cout << solve() << endl;
	return 0;
}
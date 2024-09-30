// Problem name: Building Bridges(HARD)
// Problem link: https://vjudge.net/problem/SPOJ-BRDGHRD
// Submission link: https://vjudge.net/solution/12786102

#include <bits/stdc++.h>

#define MAX ((int)100010)
#define mp make_pair
#define F first
#define S second
#define endl '\n'

using namespace std;

typedef pair<int, int> pii;

int n, subsequence[ MAX ];
pii p[ MAX ];

int maxIncreasingSubsequence(){
	subsequence[ 0 ] = p[ 0 ].S;
	int len = 0;
	for(int i = 1 ; i < n ; i++){
		if(subsequence[ len ] <= p[ i ].S)
			subsequence[ ++len ] = p[ i ].S;
		else
			subsequence[ upper_bound(subsequence, subsequence + len + 1, p[ i ].S) - subsequence ] = p[ i ].S;
	}
	return ++len;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t, a, b;
	for(cin >> t ; t-- ; ){
		cin >> n;
		for(int i = 0 ; i < n ; i++)
			cin >> p[ i ].F;
		for(int i = 0 ; i < n ; i++)
			cin >> p[ i ].S, p[ i ];
		sort(p, p + n);
		cout << maxIncreasingSubsequence() << endl;
	}
	return 0;
}
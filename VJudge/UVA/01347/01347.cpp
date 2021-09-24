// Problem name: Tour
// Problem link: https://vjudge.net/problem/UVA-1347
// Submission link: https://vjudge.net/solution/12786049

#include <bits/stdc++.h>

#define MAX ((int)1010)
#define EPS ((double)1e-5)
#define mp make_pair
#define F first
#define S second
#define sqr(x) ((x) * (x))
#define endl '\n'

using namespace std;

typedef pair<int, int> point;

double dist(point a, point b){
	return sqrt(sqr(a.F - b.F) + sqr(a.S - b.S));
}

int n;
double ans[ MAX ][ MAX ];
point p[ MAX ];

double solve(int left, int right){
	int now = max(left, right) + 1;
	if(now == n - 1)
		return dist(p[ left ], p[ now ]) + dist(p[ now ], p[ right ]);
	if(ans[ left ][ right ] >= EPS)
		return ans[ left ][ right ];
	return ans[ left ][ right ] = min(dist(p[ left ], p[ now ]) + solve(now, right), dist(p[ now ], p[ right ]) + solve(left, now));
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	while(cin >> n){
		for(int i = 0 ; i < n ; i++)
			cin >> p[ i ].F >> p[ i ].S;
		memset(ans, 0, sizeof(ans));
		cout.precision(2);
		cout.flags(ios::fixed);
		cout << solve(0, 0) << endl;
	}
	return 0;
}
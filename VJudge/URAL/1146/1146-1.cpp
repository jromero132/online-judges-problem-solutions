// Problem name: Maximum Sum
// Problem link: https://vjudge.net/problem/URAL-1146
// Submission link: https://vjudge.net/solution/12796078

#include <bits/stdc++.h>

#define MAX ((int)110)
#define endl '\n'

using namespace std;

int n, m[ MAX ][ MAX ], sum[ MAX ];

int maxIntervalSum(){
	int ans = INT_MIN, now = 0;
	for(int i = 0 ; i < n ; i++){
		now += sum[ i ];
		ans = max(ans, now);
		now = max(now, 0);
	}
	return ans;
}

int maxRectangleSum(){
	int ans = INT_MIN, now;
	for(int i = 0 ; i < n ; i++){
		memset(sum, 0, n * sizeof(sum[ 0 ]));
		for(int j = i ; j < n ; j++){
			for(int k = 0 ; k < n ; k++)
				sum[ k ] += m[ k ][ j ];
			ans = max(ans, maxIntervalSum());
		}
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < n ; j++)
			cin >> m[ i ][ j ];
	cout << maxRectangleSum() << endl;
	return 0;
}
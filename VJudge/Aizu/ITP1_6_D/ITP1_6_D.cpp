// Problem name: Matrix Vector Multiplication
// Problem link: https://vjudge.net/problem/Aizu-ITP1_6_D
// Submission link: https://vjudge.net/solution/12786133

#include <bits/stdc++.h>

#define MAX ((int)101)
#define endl '\n'

using namespace std;

int n, m, matrix[ MAX ][ MAX ], v[ MAX ], ans[ MAX ];

void mul(){
	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < m ; j++)
			ans[ i ] += matrix[ i ][ j ] * v[ j ];
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < m ; j++)
			cin >> matrix[ i ][ j ];
	for(int i = 0 ; i < m ; cin >> v[ i++ ]);
	mul();
	for(int i = 0 ; i < n ; cout << ans[ i++ ] << endl);
	return 0;
}
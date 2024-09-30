// Problem name: Box and Ball
// Problem link: https://vjudge.net/problem/AtCoder-agc002_b
// Submission link: https://vjudge.net/solution/12818909

#include <bits/stdc++.h>

#define MAX ((int)100000)
#define endl '\n'

using namespace std;

int balls[ MAX ];
bool red[ MAX ];

void initialize(int n){
	for(int i = 0 ; i < n ; i++)
		balls[ i ] = 1, red[ i ] = 0;
	red[ 0 ] = 1;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m, x, y, ans = 1;
	cin >> n >> m;
	initialize(n);
	while(m--){
		cin >> x >> y;
		balls[ --x ]--;
		balls[ --y ]++;
		if(red[ x ] && !red[ y ])
			ans++, red[ y ] = 1;
		if(!balls[ x ] && red[ x ])
			red[ x ] = 0, ans--;
	}
	cout << ans << endl;
	return 0;
}
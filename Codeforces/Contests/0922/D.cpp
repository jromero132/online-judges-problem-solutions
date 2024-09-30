// Problem name: Robot Vacuum Cleaner
// Problem link: https://codeforces.com/contest/922/problem/D
// Submission link: https://codeforces.com/contest/922/submission/35313908

#include <iostream>
#include <algorithm>

#define MAX ((int)100001)

using namespace std;

typedef long long ll;

string s[ MAX ];
int order[ MAX ];
ll S[ MAX ], H[ MAX ];

bool cmp(int a, int b){
	return S[ a ] * H[ b ] > S[ b ] * H[ a ];
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, q = 0;
	ll ans = 0;
	string now;
	cin >> n;
	for(int i = 0 ; i < n ; i++){
		cin >> s[ i ], order[ i ] = i;
		now = s[ i ];
		for(int j = 0 ; now[ j ] ; j++)
			if(now[ j ] == 's')
				S[ i ]++;
			else
				H[ i ]++;
	}
	sort(order, order + n, cmp);
	for(int i = 0 ; i < n ; i++){
		now = s[ order[ i ] ];
		for(int j = 0 ; now[ j ] ; j++)
			if(now[ j ] == 's')
				q++;
			else
				ans += q;
	}
	cout << ans;
	return 0;
}
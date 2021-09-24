// Problem name: Substring
// Problem link: https://codeforces.com/contest/919/problem/D
// Submission link: https://codeforces.com/contest/919/submission/34955611

#include <bits/stdc++.h>

#define MAX ((int)300000)
#define pb push_back

using namespace std;

typedef vector<int> vi;

int n, DP[ MAX ], in_degree[ MAX ], order[ MAX ];
string value;
vi adj[ MAX ];

bool topological_order(){
	int head = 0, tail = 0;
	for(int i = 0 ; i < n ; i++)
		if(!in_degree[ i ])
			order[ tail++ ] = i;
	int v;
	while(head < tail){
		v = order[ head++ ];
		for(int i = adj[ v ].size() ; --i >= 0 ; ){
			if(!(--in_degree[ adj[ v ][ i ] ]))
				order[ tail++ ] = adj[ v ][ i ];
		}
	}
	return tail == n;
}

int solve(){
	int ans = 0;
	for(int c = 'a' ; c <= 'z' ; c++){
		memset(DP, 0, sizeof(DP));
		for(int i = n, v ; --i >= 0 ; ){
			v = order[ i ];
			for(int j = adj[ v ].size() ; --j >= 0 ; )
				DP[ v ] = max(DP[ v ], DP[ adj[ v ][ j ] ]);
			ans = max(ans, DP[ v ] += (value[ v ] == c));
		}
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int m, a, b;
	cin >> n >> m >> value;
	for(int i = 0 ; i < m ; i++)
		cin >> a >> b, adj[ --a ].pb(--b), in_degree[ b ]++;
	if(!topological_order()){
		cout << -1;
		return 0;
	}
	cout << solve();
	return 0;
}
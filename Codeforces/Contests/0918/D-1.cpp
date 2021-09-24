// Problem name: MADMAX
// Problem link: https://codeforces.com/contest/918/problem/D
// Submission link: https://codeforces.com/contest/918/submission/35003192

#include <bits/stdc++.h>

// O(n * (n + m))

#define MAX ((int)100)
#define ALPHA ((int)26)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define endl '\n'

using namespace std;

struct state{
	int win;
	bool ready;

	state() : win(-1), ready(0){ }
};

int n;
state DP[ MAX ][ MAX ];
vector< pair<int, int> > adj[ MAX ];

void get(int u, int v){
	pair<int, int> e;
	for(int i = adj[ u ].size() ; --i >= 0 ; ){
		e = adj[ u ][ i ];
		if(!DP[ v ][ e.F ].ready)
			get(v, e.F);
		if(DP[ v ][ e.F ].win < e.S)
			DP[ u ][ v ].win = max(DP[ u ][ v ].win, e.S);
	}
	DP[ u ][ v ].ready = 1;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int m, u, v;
	char c;
	cin >> n >> m;
	for(int i = 0 ; i < m ; i++)
		cin >> u >> v >> c, adj[ --u ].pb(mp(--v, c - 'a'));
	for(int i = 0 ; i < n ; cout << endl, i++)
		for(int j = 0 ; j < n ; j++){
			if(!DP[ i ][ j ].ready)
				get(i, j);
			cout << (DP[ i ][ j ].win >= 0 ? 'A' : 'B');
		}
	return 0;
}
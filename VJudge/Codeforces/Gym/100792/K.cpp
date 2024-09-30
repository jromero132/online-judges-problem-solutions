// Problem name: King's Rout
// Problem link: https://vjudge.net/problem/Gym-100792K
// Submission link: https://vjudge.net/solution/12820846

#include <bits/stdc++.h>

#define MAX ((int)200000)
#define pb push_back
#define endl '\n'

using namespace std;

typedef vector<int> vi;

int n, deg[ MAX ], order[ MAX ];
vi adj[ MAX ];
priority_queue<int> yet;

void topologicalOrder(){
	int v, p = 0;
	while(!yet.empty()){
		v = yet.top();
		yet.pop();
		order[ p++ ] = v;
		for(int i = adj[ v ].size(), w ; --i >= 0 ; ){
			w = adj[ v ][ i ];
			if(!(--deg[ w ]))
				yet.push(w);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	int m, v, w;
	for(cin >> m ; m-- ; )
		cin >> v >> w, deg[ --v ]++, adj[ --w ].pb(v);
	for(int i = 0 ; i < n ; i++)
		if(!deg[ i ])
			yet.push(i);
	topologicalOrder();
	for(int i = n - 1 ; i ; cout << ++order[ i-- ] << ' ');
	cout << ++order[ 0 ] << endl;
	return 0;
}
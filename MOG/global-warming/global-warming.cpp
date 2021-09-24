// Problem name: E - Global Warming
// Problem link: https://matcomgrader.com/problem/9212/global-warming/
// Submission link: https://matcomgrader.com/submission/118004/

#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <map>

#define MAX (int)(2e2 + 3)
#define pb(x) push_back(x)
#define POP_COUNT(x) (__builtin_popcount(x))

using namespace std;

int n, m, adj[ MAX ][ MAX ], total = 0;
vector<int> cc;
queue<int> path;
bool check[ MAX ], ok = 1;

void BFS(int p){
	cc.clear();

	check[ p ] = 1;
	path.push(p);
	cc.pb(p);

	int now;
	while(!path.empty()){
		now = path.front();
		path.pop();
		for(int i = 0 ; i < n ; i++)
			if(adj[ now ][ i ] >= 0 && !check[ i ]){
				check [ i ] = 1;
				path.push(i);
				cc.pb(i);
			}
	}
}

void solve(int p){
	BFS(p);
	if(cc.size() & 1){
		ok = 0;
		return;
	}
	int len = cc.size(), now, match[ 1 << len ];
	memset(match, -1, sizeof(match));
	match[ 0 ] = 0;
	for(int mask = 0 ; mask < (1 << len) ; mask++){
		if(POP_COUNT(mask) & 1)
			continue;
		for(int i = 0 ; i < len ; i++){
			if(mask & (1 << i))
				continue;
			for(int j = i + 1 ; j < len ; j++){
				if(mask & (1 << j))
					continue;
				now = mask | (1 << i) | (1 << j);
				if(match[ now ] != -1)
					match[ now ] = min(match[ now ], match[ mask ] + adj[ cc[ i ] ][ cc[ j ] ]);
				else
					match[ now ] = match[ mask ] + adj[ cc[ i ] ][ cc[ j ] ];
			}
		}
	}
	total += match[ (1 << len) - 1 ];
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	memset(adj, -1, sizeof(adj));

	int p, q, c;
	cin >> n >> m;
	if(n & 1){
		cout << "impossible";
		return 0;
	}
	for(int i = 0 ; i < m ; i++){
		cin >> p >> q >> c;
		--p;
		--q;
		adj[ p ][ q ] = adj[ q ][ p ] = c;
	}
	for(int i = 0 ; i < n ; i++)
		if(!check[ i ])
			solve(i);
	if(!ok)
		cout << "impossible";
	else
		cout << total;
	return 0;
}
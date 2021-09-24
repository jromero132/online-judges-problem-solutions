// Problem name: Bacteria Experiment
// Problem link: https://codeforces.com/gym/101522/problem/B
// Submission link: https://codeforces.com/gym/101522/submission/44082268

#include <bits/stdc++.h>

#define MAX ((int)(5e5 + 3))
#define pb push_back
#define endl '\n'

using namespace std;

typedef long long ll;

vector<int> adj[ MAX ];
bool check[ MAX ];
int dist[ MAX ];

int bfs(int v){
	queue<int> path;
	path.push(v);
	memset(check, 0, sizeof(check));
	memset(dist, -1, sizeof(dist));
	check[ v ] = 1;
	dist[ v ] = 0;
	while(!path.empty()){
		v = path.front();
		path.pop();
		for(int i = adj[ v ].size() - 1, w ; i >= 0 ; --i){
			w = adj[ v ][ i ];
			if(!check[ w ]){
				check[ w ] = 1;
				path.push(w);
				dist[ w ] = dist[ v ] + 1;
			}
		}
	}
	return v;
}

int diameter(){
    return dist[ bfs(bfs(0)) ];
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);

#ifdef JoseA132
	freopen("01.in", "r", stdin);
#endif

	int n;
	cin >> n;
	for(int i = 1, u, v ; i < n ; ++i)
		cin >> u >> v, adj[ --u ].pb(--v), adj[ v ].pb(u);
	int d = diameter(), pot = 1, ans = 0;
	while(pot < d)
		++ans, pot <<= 1;
	cout << ans << endl;
	return 0;
}
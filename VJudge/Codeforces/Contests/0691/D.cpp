// Problem name: Swaps in Permutation
// Problem link: https://vjudge.net/problem/CodeForces-691D
// Submission link: https://vjudge.net/solution/16598802

#include <bits/stdc++.h>

#define pb push_back
#define endl '\n'

using namespace std;

typedef pair<int, int> pii;

vector<vector<int>> adj;
vector<bool> check;

void bfs(int v, vector<int> &p){
	vector<int> pos, val;
	queue<int> q;
	for(q.push(v), check[ v ] = 1 ; !q.empty() ; pos.pb(v), val.pb(p[ v ]), q.pop()){
		v = q.front();
		for(auto u : adj[ v ])
			if(!check[ u ]){
				check[ u ] = 1;
				q.push(u);
			}
	}
	sort(pos.begin(), pos.end());
	sort(val.begin(), val.end(), [](int a, int b){ return a > b; });
	for(int i = 0 ; i < pos.size() ; ++i)
		p[ pos[ i ] ] = val[ i ];
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);

#ifdef JoseA132
	freopen("01.in", "r", stdin);
#endif

	int n, m;
	cin >> n >> m;
	vector<int> p(n);
	check.assign(n, 0);
	adj.assign(n, vector<int>());
	for(auto &x : p)
		cin >> x, --x;
	for(int u, v ; m-- ; ){
		cin >> u >> v, --u, --v;
		adj[ u ].pb(v);
		adj[ v ].pb(u);
	}
	for(int i = 0 ; i < n ; ++i){
		if(!check[ i ])
			bfs(i, p);
		cout << p[ i ] + 1 << " \n"[ i + 1 == n ];
	}
	return 0;
}
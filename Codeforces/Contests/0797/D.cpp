// Problem name: Broken BST
// Problem link: https://codeforces.com/contest/797/problem/D
// Submission link: https://codeforces.com/contest/797/submission/44376316

#include <bits/stdc++.h>

#define F first
#define S second
#define endl '\n'

using namespace std;

vector<int> in_degree;
vector<pair<int, pair<int, int>>> adj;
multiset<int> m;

void dfs(int v, int lo = -1, int hi = 1e9 + 5){
	if(lo < adj[ v ].F && adj[ v ].F < hi)
		m.erase(adj[ v ].F);
	if(adj[ v ].S.F >= 0)
		dfs(adj[ v ].S.F, lo, min(adj[ v ].F, hi));
	if(adj[ v ].S.S >= 0)
		dfs(adj[ v ].S.S, max(lo, adj[ v ].F), hi);
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);

#ifdef JoseA132
	freopen("01.in", "r", stdin);
#endif

	int n;
	cin >> n;
	in_degree.assign(n, 0);
	adj.assign(n, { 0, { -1, -1 } });
	for(int i = 0 ; i < n ; ++i){
		int v, l, r;
		cin >> v >> l >> r;
		adj[ i ] = { v, { --l, --r } };
		m.insert(v);
		if(l >= 0) ++in_degree[ l ];
		if(r >= 0) ++in_degree[ r ];
	}
	int root;
	for(int i = 0 ; i < n ; ++i)
		if(!in_degree[ i ]){
			root = i;
			break;
		}
	dfs(root);
	cout << m.size() << endl;
	return 0;
}
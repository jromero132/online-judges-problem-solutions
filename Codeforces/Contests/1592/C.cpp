// Problem name: Bakry and Partitioning
// Problem link: https://codeforces.com/contest/1592/problem/C
// Submission link: https://codeforces.com/contest/1592/submission/130729628

#include <bits/stdc++.h>

#define INF ((int)1e6)
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

bool solve(vector<vector<int>> &tree, vector<int> &value){
	vector<int> sub_xor(tree.size());
	function<pair<int, int>(int, int)> dfs;
	dfs = [&dfs, &tree, &value, &sub_xor](int v, int p){
		sub_xor[ v ] = value[ v ];
		for(int i = 0, u ; i < tree[ v ].size() ; ++i){
			u = tree[ v ][ i ];
			if(u != p){
				auto ans = dfs(u, v);
				if(ans.first != -1)
					return ans;
				if(sub_xor[ u ] == value[ value.size() - 1 ])
					return make_pair(v, u);
				sub_xor[ v ] ^= sub_xor[ u ];
			}
		}
		return make_pair(-1, -1);
	};
	auto edge = dfs(0, -1);
	if(edge.first != -1){
		for(int k = 0 ; k < 2 ; ++k, swap(edge.first, edge.second)){
			for(auto it = tree[ edge.first ].begin() ; ; ++it){
				if(*it == edge.second){
					tree[ edge.first ].erase(it);
					break;
				}
			}
		}
		edge = dfs(0, -1);
	}
	return edge.first != -1;
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;
	for(cin >> t ; t-- ; ){
		int n, k;
		cin >> n >> k;
		vector<int> v(n + 1);
		for(int i = 0 ; i < n ; ++i)
			cin >> v[ i ], v[ n ] ^= v[ i ];
		vector<vector<int>> tree(n);
		for(int i = 1, u, v ; i < n ; ++i){
			cin >> u >> v, --u, --v;
			tree[ u ].push_back(v);
			tree[ v ].push_back(u);
		}
		cout << (v[ n ] == 0 || (solve(tree, v) && k >= 3) ? "YES" : "NO") << endl;
	}
	return 0;
}
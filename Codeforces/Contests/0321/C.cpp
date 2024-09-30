// Problem name: Ciel the Commander
// Problem link: https://codeforces.com/contest/321/problem/C
// Submission link: https://codeforces.com/contest/321/submission/34456051

#include <iostream>
#include <vector>

#define pb(x) push_back(x)
#define endl '\n'

using namespace std;


typedef vector<int> vi;
typedef vector<vi> vvi;


struct CentroidDecomposition{
private:
	int n;
	vvi adj;
	vi size, dad, depth, centroidDad, centroidDepth;
	vector<bool> check;

	int Map(int v){
		return --v;
	}

	void DFS(int u, int p = -1){
		size[ u ] = 1;
		int v;
		for(int i = adj[ u ].size() - 1 ; i >= 0 ; --i){
			v = adj[ u ][ i ];
			if(v != p && !check[ v ]){
				dad[ v ] = u;
				depth[ v ] = depth[ u ] + 1;
				DFS(v, u);
				size[ u ] += size[ v ];
			}
		}
	}

	int GetCentroid(int u){
		DFS(u);
		int n = size[ u ];
		for(int i = adj[ u ].size() - 1, v, parent = -1 ; i >= 0 ; --i){
			v = adj[ u ][ i ];
            if(v != parent && !check[ v ] && size[ v ] > (n >> 1)){
				parent = u;
	            u = v;
	            i = adj[ u ].size();
            }
		}
		return u;
	}

	void Build(int u, int p, int d){
		int centroid = GetCentroid(u);
		centroidDad[ centroid ] = p;
		centroidDepth[ centroid ] = d;
		check[ centroid ] = 1;
		for(int i = adj[ centroid ].size() - 1, v ; i >= 0 ; --i){
			v = adj[ centroid ][ i ];
			if(!check[ v ])
				Build(v, centroid, d + 1);
		}
	}

public:
	CentroidDecomposition(int n) : n(n), adj(n), size(n, 0), dad(n, -1), depth(n, 0), check(n, 0), centroidDad(n, -1), centroidDepth(n, 0){ }

	void AddEdge(int u, int v){
		adj[ u = Map(u) ].pb(v = Map(v));
		adj[ v ].pb(u);
	}

	void Build(){
		Build(0, -1, 0);
	}

	void Solve(){
		cout << (char)(centroidDepth[ 0 ] + 'A');
		for(int i = 1 ; i < n ; cout << ' ' << (char)(centroidDepth[ i++ ] + 'A'));
	}
};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, u, v;
	cin >> n;
	CentroidDecomposition cd(n);
	for(int i = 1 ; i < n ; i++)
		cin >> u >> v, cd.AddEdge(u, v);
	cd.Build();
	cd.Solve();

	return 0;
}
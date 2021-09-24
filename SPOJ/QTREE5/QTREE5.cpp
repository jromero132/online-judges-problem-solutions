// Problem name: Query on a tree V
// Problem link: https://www.spoj.com/problems/QTREE5/
// Submission link: https://www.spoj.com/submit/QTREE5/id=21032863

#include <iostream>
#include <vector>
#include <set>
 
#define pb(x) push_back(x)
#define LOG2(x) (32 - __builtin_clz(x))
#define INF ((int)(1 << 17))
#define endl '\n'
 
using namespace std;
 
typedef vector<int> vi;
typedef vector<vi> vvi;
 
struct CentroidDecomposition{
private:
	int n;
	vvi adj, dist;
	vi size, dad, depth, centroidDad, centroidDepth;
	vector< multiset<int> > minRed;
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
 
	void FindDistances(int u, int p, int h, int d){
		dist[ h ][ u ] = d;
		for(int i = adj[ u ].size() - 1, v ; i >= 0 ; --i){
			v = adj[ u ][ i ];
			if(v != p && !check[ v ])
				FindDistances(v, u, h, d + 1);
		}
	}
 
	void Build(int u, int p, int d){
		int centroid = GetCentroid(u);
		centroidDad[ centroid ] = p;
		centroidDepth[ centroid ] = d;
		check[ centroid ] = 1;
		FindDistances(centroid, -1, d, 0);
		for(int i = adj[ centroid ].size() - 1, v ; i >= 0 ; --i){
			v = adj[ centroid ][ i ];
			if(!check[ v ])
				Build(v, centroid, d + 1);
		}
	}
 
public:
	CentroidDecomposition(int n) : n(n), adj(n), size(n, 0), dad(n, -1), depth(n, 0), check(n, 0), centroidDad(n, -1), centroidDepth(n, 0), dist(LOG2(n), vi(n, 0)), minRed(n){ }
 
	void AddEdge(int u, int v){
		adj[ u = Map(u) ].pb(v = Map(v));
		adj[ v ].pb(u);
	}
 
	void Build(){
		Build(0, -1, 0);
		check.assign(n, 0);
	}
 
	int LCA(int u, int v){
		u = Map(u);
		v = Map(v);
        while(u != v){
	        if(centroidDepth[ u ] < centroidDepth[ v ])
	        	swap(u, v);
			u = centroidDad[ u ];
        }
        return u;
	}
 
	void Update(int u){
		u = Map(u);
		bool white = check[ u ] = !check[ u ];
		for(int v = u ; v != -1 ; v = centroidDad[ v ]){
			if(white)
				minRed[ v ].insert(dist[ centroidDepth[ v ] ][ u ]);
			else
				minRed[ v ].erase(minRed[ v ].find(dist[ centroidDepth[ v ] ][ u ]));
		}
	}
 
	int Query(int u){
		int ans = INF;
		for(int v = u = Map(u) ; v != -1 ; v = centroidDad[ v ])
			ans = min(ans, (minRed[ v ].empty() ? INF : *(minRed[ v ].begin())) + dist[ centroidDepth[ v ] ][ u ]);
		return ans;
	}
};
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
 
	int n, m, u, v;
	cin >> n;
	CentroidDecomposition cd(n);
	for(int i = 1 ; i < n ; i++)
		cin >> u >> v, cd.AddEdge(u, v);
	cd.Build();
	for(cin >> m ; m-- ; ){
		cin >> u >> v;
		if(u == 0)
			cd.Update(v);
		else
			cout << ((u = cd.Query(v)) == INF ? -1 : u) << endl;
	}
    return 0;
}
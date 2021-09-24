// Problem name: Query on a tree
// Problem link: https://www.spoj.com/problems/QTREE/
// Submission link: https://www.spoj.com/submit/QTREE/id=21038186

#include <iostream>
#include <vector>

#define MAX ((int)10000)
#define DAD(x) ((x) >> 1)
#define LEFT(x) ((x) << 1)
#define RIGHT(x) ((x) << 1 | 1)
#define mp(i, j) make_pair(i, j)
#define F first
#define S second
#define pb(x) push_back(x)
#define endl '\n'

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<vii> vvii;

struct SegmentTree{
private:
	int n;
	vi tree;

public:
	SegmentTree(int n) : n(n), tree(n << 1, 0){ }

	void Build(vi array){
		if(n != array.size())
			n = array.size(), tree.assign(n << 1, 0);
		for(int i = 0 ; i < n ; i++)
			tree[ i + n ] = array[ i ];
		for(int i = n - 1 ; i ; i--)
			tree[ i ] = max(tree[ LEFT(i) ], tree[ RIGHT(i) ]);
	}

	void Update(int pos, int v){
		for(tree[ pos += n ] = v ; pos ; pos = DAD(pos))
			tree[ DAD(pos) ] = max(tree[ pos ], tree[ pos ^ 1 ]);
	}

	int Query(int l, int r){
		int ans = (~0);
		for(l += n, r += n ; l < r ; l = DAD(l), r = DAD(r)){
			if(l & 1)
				ans = max(ans, tree[ l++ ]);
			if(r & 1)
				ans = max(ans, tree[ --r ]);
		}
		return ans;
	}
};

struct HeavyLightDecomposition{
private:
	int n, root;
	vi size, dad, specialChild, depth, position, chainHead, parentEdge;
	vvii adj;
	SegmentTree tree;

	int Map(int v){
		return --v;
	}

	void DFS(int u){
		size[ u ] = 1;
		for(int i = adj[ u ].size() - 1, v ; i >= 0 ; i--){
			v = adj[ u ][ i ].F;
			if(v != dad[ u ]){
				dad[ v ] = u;
				depth[ v ] = depth[ u ] + 1;
				parentEdge[ v ] = adj[ u ][ i ].S;
				DFS(v);
				size[ u ] += size[ v ];
				if(specialChild[ u ] == -1 || size[ specialChild[ u ] ] < size[ v ])
					specialChild[ u ] = v;
			}
		}
	}

	int LCA(int u, int v){
		while(chainHead[ u ] != chainHead[ v ]){
			if(depth[ chainHead[ u ] ] < depth[ chainHead[ v ] ])
				swap(u, v);
			u = dad[ chainHead[ u ] ];
		}
		return depth[ u ] < depth[ v ] ? u : v;
	}

public:
	HeavyLightDecomposition(int n) : n(n), size(n, 0), dad(n, -1), specialChild(n, -1), depth(n, 0), position(n, 0), chainHead(n, 0), parentEdge(n, 0), tree(n), adj(n){ }

	void AddEdge(int u, int v, int w){
		adj[ u = Map(u) ].pb(mp(v = Map(v), w));
		adj[ v ].pb(mp(u, w));
	}

	void Build(int from){
		root = Map(from);
		vi baseArray(n);
		DFS(root);
		for(int u = 0, pos = 0 ; u < n ; u++)
			if(dad[ u ] == -1 || specialChild[ dad[ u ] ] != u)
				for(int v = u ; v != -1 ; v = specialChild[ v ])
					chainHead[ v ] = u, position[ v ] = pos, baseArray[ pos++ ] = parentEdge[ v ];
		tree.Build(baseArray);
	}

	void Update(int u, int v, int w){
		u = Map(u);
		v = Map(v);
		if(u == dad[ v ])
			swap(u, v);
		tree.Update(position[ u ], w);
	}

	int Query(int u, int v){
		if(u == v)
			return 0;
		u = Map(u);
		v = Map(v);
		int ans = (~0);
		while(chainHead[ u ] != chainHead[ v ]){
			if(depth[ chainHead[ u ] ] < depth[ chainHead[ v ] ])
				swap(u, v);
			ans = max(ans, tree.Query(position[ chainHead[ u ] ], position[ u ] + 1));
			u = dad[ chainHead[ u ] ];
		}
		if(depth[ u ] > depth[ v ])
			swap(u, v);
		return max(ans, tree.Query(position[ u ] + 1, position[ v ] + 1));
	}
};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t, n, u, v, w;
	pii edge[ MAX ];
	for(cin >> t ; t-- ; ){
		cin >> n;
		HeavyLightDecomposition hld(n);
		for(int i = 1 ; i < n ; i++)
			cin >> u >> v >> w, hld.AddEdge(u, v, w), edge[ i - 1 ] = mp(u, v);
		hld.Build(1);
		for(string s ; cin >> s && s != "DONE" ; ){
			cin >> u >> v;
			if(s[ 0 ] == 'Q')
				cout << hld.Query(u, v) << endl;
			else
				u--, hld.Update(edge[ u ].F, edge[ u ].S, v);
		}
	}
    return 0;
}
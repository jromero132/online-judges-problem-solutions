// Problem name: Grass Planting
// Problem link: https://www.spoj.com/problems/GRASSPLA/
// Submission link: https://www.spoj.com/submit/GRASSPLA/id=21038866

#include <iostream>
#include <algorithm>
#include <vector>

#define DAD(x) ((x) >> 1)
#define LEFT(x) ((x) << 1)
#define RIGHT(x) ((x) << 1 | 1)
#define pb(x) push_back(x)
#define mp(i, j) make_pair(i, j)
#define F first
#define S second
#define LOG2(x) (31 - __builtin_clz(x))
#define endl '\n'

using namespace std;

typedef pair<int, int> pii;
typedef vector<pii> vii;

struct SegmentTree{
private:
	int height;
	vector<int> tree, lazy;

	void apply(int i, int v){
		tree[ i ] += v;
		if(i < n)
			lazy[ i ] += v;
	}

	void build(int i){
		for( ; i = DAD(i) ; )
			tree[ i ] = tree[ LEFT(i) ] + tree[ RIGHT(i) ] + lazy[ i ];
	}

	void refresh(int i){
		for(int h = height, k ; h ; h--){
			k = (i >> h);
			if(lazy[ k ] != 0){
				apply(LEFT(k), lazy[ k ]);
				apply(RIGHT(k), lazy[ k ]);
				lazy[ k ] = 0;
			}
		}
	}

public:
	int n;

	SegmentTree(int n) : n(n), height(LOG2(n)), tree(n << 1, 0), lazy(n, 0){ }

	void Update(int l, int r, int v){
		l += n;
		r += n;
		for( ; l < r ; l = DAD(l), r = DAD(r)){
			if(l & 1)
				apply(l++, v);
			if(r & 1)
				apply(--r, v);
		}
		build(l);
		build(r - 1);
	}

	int Query(int l, int r){
		l += n;
		r += n;
		refresh(l);
		refresh(r - 1);
		int ans = 0;
		for( ; l < r ; l = DAD(l), r = DAD(r)){
			if(l & 1)
				ans += tree[ l++ ];
			if(r & 1)
				ans += tree[ --r ];
		}
		return ans;
	}
};

struct HeavyLight{
private:
	int n;
	vector<int> size, dad, heavy, depth, position, head;
	vector<vii> adj;
	SegmentTree tree;

	int Map(int v){
		return --v;
	}

	int f(int a, int b){
		return a + b;
	}

public:
	HeavyLight(int n) : n(n), adj(n), tree(n) { }

	void AddEdge(int u, int v, int w){
		adj[ u = Map(u) ].pb(mp(v = Map(v), w));
		adj[ v ].pb(mp(u, w));
	}

	void DFS(int u){
		size[ u ] = 1;
		int v;
		for(int i = adj[ u ].size() - 1 ; i >= 0 ; --i){
			v = adj[ u ][ i ].F;
			if(v != dad[ u ]){
				dad[ v ] = u;
				depth[ v ] = depth[ u ] + 1;
				DFS(v);
				size[ u ] += size[ v ];
				if(heavy[ u ] == -1 || size[ heavy[ u ] ] < size[ v ])
					heavy[ u ] = v;
			}
		}
	}

	void Build(){
		size.assign(n, 0);
		dad.assign(n, -1);
		heavy.assign(n, -1);
		depth.assign(n, 0);

		DFS(0);

		position.assign(n, 0);
		head.assign(n, 0);

		for(int u = 0, pos = 0 ; u < n ; ++u)
			if(dad[ u ] == -1 || heavy[ dad[ u ] ] != u)
				for(int v = u, parent = u ; v != -1 ; parent = v, v = heavy[ v ])
					head[ v ] = u, position[ v ] = pos++;
	}

	void Update(int u, int v, int w){
		u = Map(u);
		v = Map(v);
		while(head[ u ] != head[ v ]){
			if(depth[ head[ u ] ] < depth[ head[ v ] ])
				swap(u, v);
			tree.Update(position[ head[ u ] ], position[ u ] + 1, w);
			u = dad[ head[ u ] ];
		}
		if(depth[ u ] > depth[ v ])
			swap(u, v);
		tree.Update(position[ u ] + 1, position[ v ] + 1, w);
	}

	int Query(int u, int v){
		u = Map(u);
		v = Map(v);
		int ans = 0;
		while(head[ u ] != head[ v ]){
			if(depth[ head[ u ] ] < depth[ head[ v ] ])
				swap(u, v);
			ans = f(ans, tree.Query(position[ head[ u ] ], position[ u ] + 1));
			u = dad[ head[ u ] ];
		}
		if(depth[ u ] > depth[ v ])
			swap(u, v);
		ans = f(ans, tree.Query(position[ u ] + 1, position[ v ] + 1));
		return ans;
	}
};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m, u, v;
	char ope;
	cin >> n >> m;
	HeavyLight hld(n);
	for(int i = 1 ; i < n ; i++)
		cin >> u >> v, hld.AddEdge(u, v, 0);
	hld.Build();
	while(m--){
		cin >> ope >> u >> v;
		if(ope == 'P')
			hld.Update(u, v, 1);
		else
			cout << hld.Query(u, v) << endl;
	}
	return 0;
}

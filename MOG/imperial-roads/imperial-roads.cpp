// Problem name: I - Imperial roads
// Problem link: https://matcomgrader.com/problem/9349/imperial-roads/
// Submission link: https://matcomgrader.com/submission/123819/

#include <bits/stdc++.h>

#define MAX_V ((int)(1e5))
#define LOG2_MAX_V ((int)(17))
#define MAX_E ((int)(2e5 + 1))
#define INF (int)(~(1 << 31))
#define pb push_back
#define mp make_pair
#define endl '\n'

using namespace std;

typedef pair<int, int> pii;

struct Edge{
	int v1, v2, cost, taken;

	Edge(){ }

	Edge(int v1, int v2, int cost) : v1(v1), v2(v2), cost(cost), taken(0){ }

    bool operator < (const Edge &e)const{
		return cost < e.cost;
    }
};

struct SemiEdge{
	int v, w;

	SemiEdge(){ }

	SemiEdge(int v, int w) : v(v), w(w){ }
};

struct Node{
	int value, parent, rank;

	Node() : Node(0, 0){ }

	Node(int value, int parent) : value(value), parent(parent), rank(0){ }
};

class DisjointSets{
public:
	int n;
	vector<Node> item;

	DisjointSets(int n) : n(n), item(n){ }

	void Create(int value, int pos){
		item[ pos ] = Node(value, pos);
	}

	bool Merge(int pos1, int pos2){
		pos1 = Find(pos1);
		pos2 = Find(pos2);

		if(pos1 == pos2)
			return 0;

		if(item[ pos1 ].rank > item[ pos2 ].rank)
			item[ pos2 ].parent = pos1;
		else{
			item[ pos1 ].parent = pos2;

			if(item[ pos1 ].rank == item[ pos2 ].rank)
				item[ pos2 ].rank++;
		}
		return 1;
	}

	int Find(int pos){
		return item[ pos ].parent == pos ? pos : (item[ pos ].parent = Find(item[ pos ].parent));
	}
};

int V, E, LCA[ MAX_V ][ LOG2_MAX_V ], L[ MAX_V ], Cost[ MAX_V ][ LOG2_MAX_V ];
Edge edge[ MAX_E ];
vector<SemiEdge> G[ MAX_V ], Transpose[ MAX_V ];
map< pii, int > EDGES;
set< pii > MST;
queue<int> Q;

int Kruskal(){
	sort(edge, edge + E);

	DisjointSets forest(V);

	int a, b, mst = 0;
	for(int i = 0 ; i < V ; i++)
		forest.Create(i, i);

	for(int i = 0 ; i < E ; i++){
		a = forest.Find(edge[ i ].v1);
		b = forest.Find(edge[ i ].v2);
		if(a != b){
			mst += edge[ i ].cost;
			edge[ i ].taken = 1;
			Transpose[ edge[ i ].v1 ].pb(SemiEdge(edge[ i ].v2, edge[ i ].cost));
			Transpose[ edge[ i ].v2 ].pb(SemiEdge(edge[ i ].v1, edge[ i ].cost));
			if(forest.Merge(a, b))
                MST.insert(mp(min(edge[ i ].v1, edge[ i ].v2), max(edge[ i ].v1, edge[ i ].v2)));
		}
	}
	return mst;
}

void RMQ(){
	for(Q.push(0), L[ 0 ] = 1 ; !Q.empty() ; Q.pop()){
		int now = Q.front();
		for(int i = 0 ; i < Transpose[ now ].size(); i++){
			int next = Transpose[ now ][ i ].v;
			if(!L[ next ]){
				LCA[ next ][ 0 ] = now;
				Cost[ next ][ 0 ] = Transpose[ now ][ i ].w;
				L[ next ] = L[ now ] + 1;
				Q.push(next);
			}
		}
	}

	for(int j = 1 ; (1 << j) <= V ; j++)
		for(int i = 0 ; i < V ; i++){
			LCA[ i ][ j ] = LCA[ LCA[ i ][ j - 1 ] ][ j - 1 ];
			Cost[ i ][ j ] = max(Cost[ i ][ j - 1 ], Cost[ LCA[ i ][ j - 1 ] ][ j - 1 ]);
		}
}

int Query(int v1, int v2){
	if(L[ v1 ] > L[ v2 ])
		swap(v1, v2);

	int ans = 0;
	for(int i = log2(L[ v2 ]) ; i >= 0 ; i--)
		if(L[ v2 ] - (1 << i) >= L[ v1 ]){
			ans = max(ans, Cost[ v2 ][ i ]);
			v2 = LCA[ v2 ][ i ];
		}

	if(v1 == v2)
		return ans;

	for(int i = log2(L[ v1 ]); i >= 0 ; i--)
		if(LCA[ v1 ][ i ] && LCA[ v1 ][ i ] != LCA[ v2 ][ i ]){
			ans = max(ans, max(Cost[ v1 ][ i ], Cost[ v2 ][ i ]));
			v1 = LCA[ v1 ][ i ];
			v2 = LCA[ v2 ][ i ];
		}

	return max(ans, max(Cost[ v1 ][ 0 ], Cost[ v2 ][ 0 ]));
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> V >> E;
    int v, w, c, q, mst;
    for(int i = 0 ; i < E ; i++){
        cin >> v >> w >> c;
        edge[ i ] = Edge(--v, --w, c);
        G[ v ].pb(SemiEdge(w, c));
        G[ w ].pb(SemiEdge(v, c));
        EDGES[ mp(min(v, w), max(v, w)) ] = c;
    }
    mst = Kruskal();
    RMQ();
    for(cin >> q ; q-- ; ){
        cin >> v >> w;
        if(--v > --w)
            swap(v, w);
        if(MST.find(mp(v, w)) != MST.end())
            cout << mst << endl;
        else
            cout << mst - Query(v, w) + EDGES[ mp(v, w) ] << endl;
    }
	return 0;
}
// Problem name: Gasoline
// Problem link: https://codeforces.com/gym/101908/problem/G
// Submission link: https://codeforces.com/gym/101908/submission/44967296

#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define DB( x ) cout << #x << " = " << x << endl;
#define LEFT(n) (2 * (n))
#define RIGHT(n) (2 * (n) + 1)

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pii;
typedef pair<pii, int> piii;
typedef pair<pii, pii> piiii;
typedef pair<double, double> point;

const ll INF = 2e8;
const double EPS = 1e-6;
const ll MOD = (ll)(1000000007);
const ll MAXV = (ll)(4e3 + 5);
const ll MAXE = (ll)(4e4 + 10);
const ll MAXLOG = (ll)(20);

struct edge{
	int dest;
	int cap, flow;
	int next;
	int time;
	edge(int _dest, int _cap, int _next, int _time){
		dest = _dest, cap = _cap, next = _next, time = _time;
		flow = 0LL;
	}
	edge(){}
};

int first[MAXV];
int top;
edge G[2 * MAXE];
int source, sink;

void add_edge(int u, int v, int cap, int time){
	G[top] = (edge){v, cap, first[u], time};
	first[u] = top ++;
	G[top] = (edge){u, 0, first[v], time};
	first[v] = top ++;
}
int T;
int Q[MAXV];
int lev[MAXV];
bool bfs(){
	int enq, deq;
	enq = deq = 0;
	for(int i = 0;i <= sink;i ++)
		lev[i] = -1;
	lev[source] = 0;
	Q[enq ++] = source;
	while(deq < enq && lev[sink] == -1){
		int u = Q[deq ++];
		for(int i = first[u];i != -1;i = G[i].next){
			int v = G[i].dest;
			if(G[i].time > T)continue;
			if(lev[v] == -1 && G[i].cap > G[i].flow){
				lev[v] = lev[u] + 1;
				Q[enq ++] = v;
			}
		}
	}
	return lev[sink] != -1;
}

int now[MAXV];
int dfs(int u, int flow){
	if(u == sink)
		return flow;
	int f = 0;
	for(int i  = now[u];i != -1;i = now[u] = G[i].next){
		int v = G[i].dest;
		if(G[i].time > T)continue;
		if(lev[v] == lev[u] + 1 && G[i].cap > G[i].flow){
			f = dfs(v, min(flow, G[i].cap - G[i].flow));
			if(f){
				G[i].flow += f;
				G[i ^ 1].flow -= f;
				return f;
			}
		}
	}
	return 0LL;
}

int max_flow(){
	int flow = 0;
	int pf;
	while(bfs()){
		for(int i = 0;i <= sink;i ++)
			now[i] = first[i];
		while(pf = dfs(source, INF))
			flow += pf;
	}
	return flow;
}

int C, R, E;
int demanda[MAXV], oferta[MAXV];
int sum = 0;

bool f(int time){
	for(int i = 0;i < top;i ++)
		G[i].flow = 0;
	T = time;
	return max_flow() == sum;
}



int main(){
	ios_base::sync_with_stdio(0);cin.tie( 0 );

	cin >> C >> R >> E;

	memset(first, -1, sizeof(first));
	source = C + R;
	sink = source + 1;


	for(int i = 0;i < C;i ++){
		cin >> demanda[i];
		sum += demanda[i];
		add_edge(i + R, sink, demanda[i], 0);
	}
	for(int i = 0;i < R;i ++){
		cin >> oferta[i];
		add_edge(source, i, oferta[i], 0);
	}

	for(int i = 0;i < E;i ++){
		int a, b, t;
		cin >> a >> b >> t;
		a --, b --;
		a += R;
		add_edge(b, a, INF, t);
	}



	int lo = 1, hi = (ll)(1e6 + 10), mi;

	if(!f(hi)){
		cout << "-1\n";
		return 0;
	}

	while(lo + 2 < hi){
		mi = (lo + hi) >> 1;
		if(f(mi))
			hi = mi;
		else
			lo = mi;
	}

	while(!f(lo))lo ++;

	cout << T << "\n";

	return 0;
}
// Problem name: Jumping along the Hummocks
// Problem link: https://codeforces.com/gym/100090/problem/M
// Submission link: https://codeforces.com/gym/100090/submission/20993414

#include <bits/stdc++.h>

using namespace std;

#define DB( x ) cout << #x << " = " << x << endl;
#define LEFT(n) (2 * (n))
#define RIGHT(n) (2 * (n) + 1)
#define X real()
#define Y imag()

typedef long long ll;
typedef pair<int, int> node;
typedef complex<double> P;

const ll INF = 1e9;
const double EPS = 1e-6;
const ll MOD = (ll)(1e5);
const ll MAXV = (ll)(2e5 + 10);
const ll MAXE = (ll)(1e6 + 10);

vector <int> G[MAXV];

struct cmp{
	bool operator()(const node &a, const node &b){
		return a.second > b.second;
	}
};

int nex[MAXV];
int n;
int arr[MAXV];
bool mark[MAXV];
int dist[MAXV];

priority_queue <node, vector<node>, cmp> Q;

int bfs(){
	int u, w;
	for(int i = 0;i <= n;i ++)
		dist[i] = INF;

	dist[0] = 0;
	Q.push(node(0, 0));
	while(!Q.empty()){
		u = Q.top().first;
		if(mark[u])
			continue;
		mark[u] = true;
		if(u == n - 1)
			return dist[u];
		Q.pop();
		for(int i = 0;i < (int)G[u].size();i ++){
			int v;
			v = G[u][i];
			if(!mark[v] && dist[v] > dist[u] + 1){
				dist[v] =dist[u] + 1;
				Q.push(node(v, dist[v]));
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);

	memset(nex, -1, sizeof(nex));

	scanf("%d", &n);

	for(int i = 0;i < n;i ++){
		scanf("%d", &arr[i]);
	}

	for(int i = n - 1;i >= 0;i --){
		if(nex[arr[i]] == -1){
			nex[arr[i]] = i;
		}
		else{
			G[i].push_back(nex[arr[i]]);
			nex[arr[i]] = i;
		}
		G[i].push_back(i + 1);
	}

	printf("%d\n", bfs());

	return 0;
}
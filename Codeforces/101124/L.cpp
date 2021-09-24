// Problem name: Subway
// Problem link: https://codeforces.com/gym/101124/problem/L
// Submission link: https://codeforces.com/gym/101124/submission/21385875

#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<cstring>
#include<string>
#include<cmath>
#include<stack>
#include<queue>
#include<cstdlib>
#include<map>
//#include <bits/stdc++.h>

using namespace std;

#define DB( x ) cout << #x << " = " << x << endl;
#define LEFT(n) (2 * (n))
#define RIGHT(n) (2 * (n) + 1)
#define X real()
#define Y imag()

typedef long long ll;
typedef pair<int, double> node;
//typedef complex<double> P;

const ll INF = 1e18;
const double EPS = 1e-6;
const ll MOD = (ll)(1e5);
const ll MAXV = (ll)(1e4 + 1000);
const ll MAXE = (ll)(1e6 + 10);

struct cmp{
	bool operator()(const node &a, const node &b){
		return a.second > b.second;
	}
};

int V, S;

struct P{
	int id;
	double x, y;
	P(double _x, double _y, int _id){
		x = _x;
		y = _y;
		id = _id;
	}
	P(){}
};

P h;
P s;

vector <P> subway[MAXV];
vector <P> nodos;
vector <node> G[MAXV];

double dist(P a, P b){
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double tim(P a, P b, double v){
	double w = dist(a, b);
	w /= 1000.0;
	return w / v;
}

bool mark[MAXV];
double D[MAXV];

priority_queue<node, vector<node>, cmp> Q;

double dijkstra(){
	int u = 0;
	for(int i = 0;i <= V;i ++){
		D[i] = (double)INF;
		mark[i] = false;
	}
	D[u] = 0.0;
	Q.push(node(u, 0.0));

	while(!Q.empty()){
		u = Q.top().first;
		Q.pop();
		if(mark[u])
			continue;
		mark[u] = true;
		for(int i = 0, v;i < (int)G[u].size();i ++){
			v = G[u][i].first;
			if(!mark[v] && D[v] > D[u] + G[u][i].second){
				D[v] = D[u] + G[u][i].second;
				Q.push(node(v, D[v]));
			}
		}
	}
	return D[1];
}

int main(){
	ios_base::sync_with_stdio(0);

	scanf("%lf%lf%lf%lf", &h.x, &h.y, &s.x, &s.y);
	h.id = 0;
	s.id = 1;
	subway[0].push_back(h);
	subway[1].push_back(s);

	double x, y;

	S = 2;
	V = 2;
	while(scanf("%lf%lf", &x, &y) != EOF){
		if(x == -1 && y == -1){
			S ++;
			continue;
		}
		subway[S].push_back((P){x, y, V ++});
	}

	for(int i = 0;i < S;i ++){
		for(int j = 0;j < (int)subway[i].size();j ++){
			for(int k = 0;k < S;k ++)
				for(int l = 0;l < (int)subway[k].size();l ++){
					if(subway[i][j].id != subway[k][l].id){
						int u = subway[i][j].id;
						int v = subway[k][l].id;
						double t = tim(subway[i][j], subway[k][l], 10.0);
						G[u].push_back(node(v, t));
						G[v].push_back(node(u, t));
					}
				}
		}
	}

	for(int i = 0;i < S;i ++)
		for(int j = 0;j < (int)subway[i].size() - 1;j ++){
			int u = subway[i][j].id;
			int v = subway[i][j + 1].id;
			double t = tim(subway[i][j], subway[i][j + 1], 40.0);
			G[u].push_back(node(v, t));
			G[v].push_back(node(u, t));
		}

	double sol = dijkstra();
	//printf("%lf\n", sol);

	double res = sol * 60.0;
	//printf("%.0lf\n", (double)INF);
	printf("%.0lf\n", res);

	return 0;
}
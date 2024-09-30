// Problem name: Rectangles
// Problem link: https://vjudge.net/problem/UVA-11930
// Submission link: https://vjudge.net/solution/16352874

#include <bits/stdc++.h>

#define EPS ((double)1e-12)
#define pb push_back
#define VAR(x) ((x) << 1)
#define NOT(x) ((x) ^ 1)
#define endl '\n'

using namespace std;

struct two_satisfability{
	int n, time;
	vector<int> dt, low, scc;
	vector<vector<int>> G;
	stack<int> s;

	two_satisfability(int n) : n(n), time(0), dt(n << 1, 0), low(n << 1, 0), scc(n << 1), G(n << 1){ }

	void add_set(int u){ add_or(u, u); }
	void add_not(int u){ add_or(NOT(u), NOT(u)); }
	void add_or(int u, int v){ G[ NOT(u) ].pb(v), G[ NOT(v) ].pb(u); }
	void add_nor(int u, int v){ add_or(NOT(u), NOT(u)); add_or(NOT(v), NOT(v)); }
	void add_and(int u, int v){ add_or(u, u); add_or(v, v); }
	void add_nand(int u, int v){ add_or(NOT(u), NOT(v)); }
	void add_xor(int u, int v){ add_or(u, v); add_or(NOT(u), NOT(v)); }
	void add_implication(int u, int v){ add_or(NOT(u), v); }
	void add_double_implication(int u, int v){ add_or(NOT(u), v); add_or(u, NOT(v)); }

	void dfs(int v){
		dt[ v ] = low[ v ] = ++time;
        s.push(v);
		for(int u : G[ v ])
			low[ v ] = min(low[ v ], !dt[ u ] ? dfs(u), low[ u ] : (!scc[ u ] ? dt[ u ] : low[ v ]));
		if(dt[ v ] == low[ v ]){
			do{
				scc[ s.top() ] = time, s.pop();
			}while(!scc[ v ]);
		}
	}

	bool solve(){
		for(int i = 0 ; i < n ; ++i){
			int x = VAR(i);
			if(!dt[ x ]) dfs(x);
			if(!dt[ NOT(x) ]) dfs(NOT(x));
			if(scc[ x ] == scc[ NOT(x) ]) return 0;
		}
		return 1;
	}
};

struct point{
	double x, y;
	point() : x(0), y(0){ }
	point(double x, double y) : x(x), y(y){ }
	point(const point &p) : x(p.x), y(p.y){ }
	point operator -(const point &p) const{ return point(x - p.x, y - p.y); }
	friend istream &operator >>(istream &in, point &p){ in >> p.x >> p.y; return in; }
};

double dot(point a, point b){ return a.x * b.x + a.y * b.y; }
double dist2(point a, point b){ return dot(a - b, a - b); }
double cross(point a, point b){ return a.x * b.y - a.y * b.x; }

bool lines_parallel(point a, point b, point c, point d){
	return fabs(cross(b - a, c - d)) < EPS;
}

bool lines_collinear(point a, point b, point c, point d){
	return lines_parallel(a, b, c, d) && fabs(cross(a - b, a - c)) < EPS && fabs(cross(c - d, c - a)) < EPS;
}

bool segments_intersect(point a, point b, point c, point d){
	if(lines_collinear(a, b, c, d)){
		if(dist2(a, c) < EPS || dist2(a, d) < EPS || dist2(b, c) < EPS || dist2(b, d) < EPS)
			return true;
		if(dot(c - a, c - b) > 0 && dot(d - a, d - b) > 0 && dot(c-b, d-b) > 0)
			return false;
		return true;
	}
	if(cross(d - a, b - a) * cross(c - a, b - a) > 0)
		return false;
	if(cross(a - c, d - c) * cross(b - c, d - c) > 0)
		return false;
return true;
}

struct rectangle{
	point p1, p2, p3, p4;

	rectangle(point _p1, point _p2, point _p3, point _p4) : p1(_p1), p2(_p2), p3(_p3), p4(_p4){
		if(dist2(p1, p2) > dist2(p1, p3))
			swap(p2, p3);
		if(dist2(p1, p3) < dist2(p1, p4))
			swap(p3, p4);
	}
};

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);

#ifdef JoseA132
	freopen("01.in", "r", stdin);
#endif

	int n;
	while(cin >> n && n){
		two_satisfability ts(n);
		vector<rectangle> r;
		for(int i = 0 ; i < n ; ++i){
			point p1, p2, p3, p4;
			cin >> p1 >> p2 >> p3 >> p4;
			r.pb(rectangle(p1, p2, p3, p4));
			for(int j = 0 ; j < i ; ++j){
				if(segments_intersect(r[ i ].p1, r[ i ].p3, r[ j ].p1, r[ j ].p3))
					ts.add_nand(VAR(i), VAR(j));
				if(segments_intersect(r[ i ].p1, r[ i ].p3, r[ j ].p2, r[ j ].p4))
					ts.add_nand(VAR(i), NOT(VAR(j)));
				if(segments_intersect(r[ i ].p2, r[ i ].p4, r[ j ].p1, r[ j ].p3))
					ts.add_nand(NOT(VAR(i)), VAR(j));
				if(segments_intersect(r[ i ].p2, r[ i ].p4, r[ j ].p2, r[ j ].p4))
					ts.add_nand(NOT(VAR(i)), NOT(VAR(j)));
			}
		}
		cout << (ts.solve() ? "YES" : "NO") << endl;
	}
	return 0;
}
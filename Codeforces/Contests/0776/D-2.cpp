// Problem name: The Door Problem
// Problem link: https://codeforces.com/contest/776/problem/D
// Submission link: https://codeforces.com/contest/776/submission/43970737

#include <bits/stdc++.h>

#define pb push_back
#define sz(x) ((int)(x).size())
#define VAR(x) ((x) << 1)
#define NOT(x) ((x) ^ 1)
#define TRUE(x) (VAR(x) << 1)
#define FALSE(x) ((x) | 1)
#define endl '\n'

using namespace std;

struct two_satisfability{
	int n, time;
	vector<int> dt, low, scc;
	vector<vector<int>> G;
	stack<int> s;

	two_satisfability(int n) : n(n), time(0), dt(n << 1, 0), low(n << 1, 0), scc(n << 1), G(n << 1){ }

	void add_set(int u){ add_or(u, u); } // (u) clause taken as (u | u) clause.
	void add_not(int u){ add_or(NOT(u), NOT(u)); } // (!u) clause taken as (!u | !u) clause.
	void add_or(int u, int v){ G[ NOT(u) ].pb(v), G[ v ].pb(NOT(u)); } // (u | v) clause taken as (!u => v) clause.
	void add_nor(int u, int v){ add_or(NOT(u), NOT(u)); add_or(NOT(v), NOT(v)); } // !(u | v) clause taken as (!u | !u) & (!v | !v) clause.
	void add_and(int u, int v){ add_or(u, u); add_or(v, v); } // (u & v) clause taken as (u | u) & (v | v) clause.
	void add_nand(int u, int v){ add_or(NOT(u), NOT(v)); } // !(u & v) clause taken as (!u | !v) clause.
	void add_xor(int u, int v){ add_or(u, v); add_or(NOT(u), NOT(v)); } // (u ^ v) clause taken as (u | v) & (!u | !v) clause.
	void add_implication(int u, int v){ add_or(NOT(u), v); } // (u => v) clause taken as (!u | v) clause.
	void add_double_implication(int u, int v){ add_or(NOT(u), v); add_or(u, NOT(v)); } // (u <=> v) clause taken as (!u | v) & (u | !v) clause.

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

	bool solve(vector<bool> &out){
		out.assign(n, 0);
		for(int i = 0 ; i < n ; ++i){
			int x = VAR(i);
			if(!dt[ x ])
				dfs(x);
			if(!dt[ NOT(x) ])
				dfs(NOT(x));
			if(scc[ x ] == scc[ NOT(x) ])
				return 0;
			out[ i ] = (scc[ x ] < scc[ NOT(x) ]);
		}
		return 1;
	}
};

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);

#ifdef JoseA132
	freopen("01.in", "r", stdin);
#endif

	int n, m;
	cin >> n >> m;
	two_satisfability ts(m);
	vector<int> door(n);
	vector<vector<int>> switches(n, vector<int>(0));
	for(auto &d : door)
		cin >> d;
	for(int i = 0, k ; i < m ; ++i){
		cin >> k;
		for(int j = 0, s ; j < k ; ++j)
			cin >> s, switches[ --s ].pb(i);
	}
	for(int i = 0 ; i < sz(switches) ; ++i){
		if(door[ i ])
			ts.add_double_implication(VAR(switches[ i ][ 0 ]), VAR(switches[ i ][ 1 ]));
		else
			ts.add_xor(VAR(switches[ i ][ 0 ]), VAR(switches[ i ][ 1 ]));
	}
	vector<bool> ans;
	cout << (ts.solve(ans) ? "YES" : "NO") << endl;
	return 0;
}
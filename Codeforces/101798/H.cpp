// Problem name: Cylindrical Graphs
// Problem link: https://codeforces.com/gym/101798/problem/H
// Submission link: https://codeforces.com/gym/101798/submission/43376497

#include <bits/stdc++.h>

#define MAX ((int)(1e5 + 3))
#define pb push_back
#define sz(x) ((int)(x).size())
#define endl '\n'

using namespace std;

vector<int> adj[ MAX ];
int deg[ MAX ];
bool check[ MAX ];
vector<int> cycle[ 2 ];

bool ok(int v1, int v2, int n){
	int u1 = v1, u2 = v2;
	bool ready;
	cycle[ 0 ].clear();
	cycle[ 1 ].clear();
	memset(check, 0, sizeof(check));
	do{
		check[ u1 ] = check[ u2 ] = 1;
		ready = 0;
		cycle[ 0 ].pb(u1);
		cycle[ 1 ].pb(u2);
		n -= 2;
		for(auto w1 : adj[ u1 ]){
			for(auto w2 : adj[ u2 ]){
				if(w1 == u2 || w2 == u1 || check[ w1 ] || check[ w2 ])
					continue;
				bool ok = 0;
				for(auto x : adj[ w1 ])
					if(x == w2){
						ok = 1;
						break;
					}
				if(ok){
					u1 = w1, u2 = w2;
					ready = 1;
					break;
				}
			}
			if(ready)
				break;
		}
		if(!ready){
			if(n)
				return 0;
			for(auto w1 : adj[ u1 ])
				for(auto w2 : adj[ u2 ])
					if(w1 == v1 && w2 == v2)
						return 1;
			return 0;
		}
	}while(u1 != v1 && u2 != v2);
	return !n;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0);

#ifdef JoseA132
	freopen("01.in", "r", stdin);
#endif

	int n, m;
	cin >> n;
	m = (3 * n) >> 1;
	for(int i = 0, u, v ; i < m ; i++){
		cin >> u >> v;
		deg[ --u ]++;
		deg[ --v ]++;
		adj[ u ].pb(v);
		adj[ v ].pb(u);
	}
	for(int i = 0 ; i < n ; i++)
		if(deg[ i ] != 3){
			cout << "NO" << endl;
			return 0;
		}
	for(auto v : adj[ 0 ])
		if(ok(0, v, n)){
			cout << "YES" << endl;
			for(int i = 0 ; i < sz(cycle[ 0 ]) ; i++)
				cout << cycle[ 0 ][ i ] + 1 << " \n"[ i + 1 == sz(cycle[ 0 ]) ];
			for(int i = 0 ; i < sz(cycle[ 1 ]) ; i++)
				cout << cycle[ 1 ][ i ] + 1 << " \n"[ i + 1 == sz(cycle[ 1 ]) ];
			return 0;
		}
	cout << "NO" << endl;
	return 0;
}
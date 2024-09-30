// Problem name: Forest (B) - Chicken
// Problem link: https://codeforces.com/gym/101798/problem/D
// Submission link: https://codeforces.com/gym/101798/submission/43225720

#include <bits/stdc++.h>

#define MAX ((int)(1e5 + 1))
#define pb push_back
#define sz(x) ((int)(x).size())
#define endl '\n'

using namespace std;

vector<int> adj[ MAX ];
int now = 0, value[ MAX ];
vector<int> preorder;

void dfs(int v){
	for(auto u : adj[ v ])
		dfs(u);
	value[ v ] = ++now;
}

void get(int v){
	preorder.pb(value[ v ]);
	for(auto u : adj[ v ])
		get(u);
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0);

#ifdef JoseA132
	freopen("01.in", "r", stdin);
#endif

	int n;
	cin >> n;
	vector<int> root;
	for(int i = 0, v ; i < n ; i++){
		cin >> v;
		if(!v)
			root.pb(i);
		else
			adj[ --v ].pb(i);
	}
	for(auto r : root)
		dfs(r), get(r);
	for(int i = 0 ; i < sz(preorder) ; i++)
		cout << preorder[ i ] << " \n"[ i + 1 == sz(preorder) ];
	cout << endl;
	return 0;
}
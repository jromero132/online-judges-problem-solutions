// Problem name: Cyclic Components
// Problem link: https://codeforces.com/contest/977/problem/E
// Submission link: https://codeforces.com/contest/977/submission/37961974

#include <bits/stdc++.h>

#define MAX ((int)200001)
#define pb push_back
#define F first
#define S second
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

vector<int> adj[ MAX ];
int n, cc = 0, CC[ MAX ], vertex[ MAX ], edge[ MAX ];
bool deg1[ MAX ];

void BFS(int v){
	cc++;
	queue<int> path;
	path.push(v);
	CC[ v ] = cc;
	vertex[ cc ]++;
	while(!path.empty()){
		v = path.front();
		edge[ cc ] += adj[ v ].size();
		deg1[ cc ] |= (adj[ v ].size() == 1);
		path.pop();
		for(int i = adj[ v ].size(), w ; --i >= 0 ; ){
			w = adj[ v ][ i ];
			if(!CC[ w ]){
				CC[ w ] = cc;
				vertex[ cc ]++;
				path.push(w);
			}
		}
	}
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, v, w;
    cin >> n >> m;
    for(int i = 0 ; i < m ; i++)
    	cin >> v >> w, adj[ v ].pb(w), adj[ w ].pb(v);
    for(int i = 1 ; i <= n ; i++)
    	if(!CC[ i ])
    		BFS(i);
    v = 0;
    for(int i = 1 ; i <= cc ; i++){
    	if(edge[ i ] == 2 * vertex[ i ])
    		v += !deg1[ i ];
    }
    cout << v << endl;
    return 0;
}
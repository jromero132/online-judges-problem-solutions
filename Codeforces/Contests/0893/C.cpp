// Problem name: Rumor
// Problem link: https://codeforces.com/contest/893/problem/C
// Submission link: https://codeforces.com/contest/893/submission/32585498

#include <bits/stdc++.h>

#define MAX (int)(1e5 + 1)
#define MOD (int)(3)
#define mod(x) (((x) % MOD + MOD) % MOD)
#define pb(x) push_back(x)
#define endl '\n'

using namespace std;

typedef long long ll;

bool check[ MAX ];
ll cost[ MAX ];
vector<int> adj[ MAX ];

ll BFS(int i){
	queue<int> path;
	path.push(i);
	check[ i ] = 1;
	ll ans = cost[ i ];
	while(!path.empty()){
		for(int i = adj[ path.front() ].size() - 1 ; i >= 0 ; i--)
			if(!check[ adj[ path.front() ][ i ] ]){
				path.push(adj[ path.front() ][ i ]);
				check[ adj[ path.front() ][ i ] ] = 1;
				ans = min(ans, cost[ adj[ path.front() ][ i ] ]);
			}
		path.pop();
	}
	return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	int n, m, v1, v2;
	ll ans = 0;
	cin >> n >> m;
	for(int i = 0 ; i < n ; cin >> cost[ i++ ]);
	for(int i = 0 ; i < m ; i++){
		cin >> v1 >> v2;
		v1--;
		v2--;
		adj[ v1 ].pb(v2);
		adj[ v2 ].pb(v1);
	}
	for(int i = 0 ; i < n ; i++)
		if(!check[ i ])
			ans += BFS(i);
	cout << ans;
    return 0;
}
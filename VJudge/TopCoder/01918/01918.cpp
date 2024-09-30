// Problem name: FlowerGarden
// Problem link: https://vjudge.net/problem/TopCoder-1918
// Submission link: https://vjudge.net/solution/31753537

#include <bits/stdc++.h>

#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define F0R(i, end) for(int i = 0 ; i < (end) ; ++i)
#define FOR(i, begin, end) for(int i = (begin) ; i < (end) ; ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

class FlowerGarden{
public:
	vi getOrdering(vi height, vi bloom, vi wilt){
		vi in_deg(sz(height), 0);
		vvi graph(sz(height));
		priority_queue<pii> pq;
		F0R(i, sz(height)){
			FOR(j, i + 1, sz(height)){
				if(max(bloom[ i ], bloom[ j ]) <= min(wilt[ i ], wilt[ j ])){
					if(height[ i ] < height[ j ])
						graph[ i ].pb(j), ++in_deg[ j ];
					else
						graph[ j ].pb(i), ++in_deg[ i ];
				}
			}
			if(!in_deg[ i ])
				pq.push(make_pair(height[ i ], i));
		}
		vi ans;
		while(!pq.empty()){
			pii t = pq.top();
			pq.pop();
			int v = t.second;
			ans.pb(height[ v ]);
			F0R(i, sz(graph[ v ])){
				int u = graph[ v ][ i ];
				if(!--in_deg[ u ])
					pq.push(make_pair(height[ u ], u));
			}
		}
		return ans;
	}
};
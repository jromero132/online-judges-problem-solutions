// Problem name: Security Badge
// Problem link: https://codeforces.com/gym/101652/problem/T
// Submission link: https://codeforces.com/gym/101652/submission/43703732

#include <bits/stdc++.h>

#define MAX ((int)1e3)
#define pb push_back
#define F first
#define S second
#define endl '\n'

using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> edge;

vector<edge> adj[ MAX ];

bool bfs(int n, int s, int t, int x){
	vector<bool> check(n, 0);
	queue<int> q;
	for(q.push(s), check[ s ] = 1 ; !q.empty() ; q.pop()){
		int v = q.front();
		if(v == t)
			return 1;

		for(auto u : adj[ v ]){
			if(check[ u.F ] || u.S.F > x || u.S.S <= x)
				continue;

			check[ u.F ] = 1;
			q.push(u.F);
		}
	}
	return 0;
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);

#ifdef JoseA132
	freopen("01.in", "r", stdin);
#endif

	int n, m, k, s, t;
	cin >> n >> m >> k >> s >> t, --s, --t;
	vector<int> v;
	for(int i = 0, a, b, c, d ; i < m ; ++i)
		cin >> a >> b >> c >> d, adj[ --a ].pb({ --b, {c, d + 1 } }), v.pb(c), v.pb(d + 1);
	sort(v.begin(), v.end());
	int ans = 0, last = -1;
	for(auto x : v){
		if(last != -1)
			ans += x - last;
		last = (bfs(n, s, t, x) ? x : -1);
	}
	cout << ans << endl;
	return 0;
}
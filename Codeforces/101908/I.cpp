// Problem name: Switches
// Problem link: https://codeforces.com/gym/101908/problem/I
// Submission link: https://codeforces.com/gym/101908/submission/44966456

#include <bits/stdc++.h>

#define pb push_back
#define endl '\n'

using namespace std;


int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);

#ifdef JoseA132
	freopen("01.in", "r", stdin);
#endif

	int n, m, k;
	cin >> n >> m >> k;
	if(!k){
		cout << 0 << endl;
		return 0;
	}
	vector<bool> bulb(m + 1, 0);
	vector<vector<int>> switches(n, vector<int>());
	for(int i = 0, x ; i < k ; ++i)
		cin >> x, bulb[ x ] = 1;
	for(int i = 0 ; i < n ; ++i){
		cin >> k;
		for(int j = 0, x ; j < k ; ++j)
			cin >> x, switches[ i ].pb(x);
	}
	for(int i = 0 ; i < (n << 1) ; ++i){
		for(auto x : switches[ i % n ])
			bulb[ x ] = !bulb[ x ];
		bool any = 0;
		for(auto x : bulb)
			any |= x;
		if(!any){
			cout << ++i << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}
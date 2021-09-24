// Problem name: Cave
// Problem link: https://codeforces.com/gym/100523/problem/J
// Submission link: https://codeforces.com/gym/100523/submission/35740580

#include <bits/stdc++.h>

#define MAX ((int)3000001)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define endl '\n'

using namespace std;

typedef pair<int, int> node;

vector<node> tree;
int n, freq[ MAX ];

void DFS(){
	for(int i = n ; --i ; )
		tree[ tree[ i ].F ].S += tree[ i ].S;
}

void update(){
	for(int i = 0 ; i < n ; freq[ tree[ i++ ].S ]++);
}

void solve(){
	cout << 1;
	int now;
	for(int i = n - 1 ; i > 1 ; i--){
		if(!(n % i)){
			now = 0;
			for(int k = i ; k <= n ; k += i)
				now += freq[ k ];
			if(now * i == n)
				cout << ' ' << n / i;
		}
	}
	cout << ' ' << n << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.sync_with_stdio(0);
	cin.tie(0);

	int v;
	cin >> n;
	tree.pb(mp(-1, 1));
	for(int i = 1 ; i < n ; i++)
		cin >> v, tree.pb(mp(--v, 1));
	DFS();
	update();
	solve();
	return 0;
}
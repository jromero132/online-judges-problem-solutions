// Problem name: Union of Doubly Linked Lists
// Problem link: https://codeforces.com/contest/847/problem/A
// Submission link: https://codeforces.com/contest/847/submission/30951884

#include <bits/stdc++.h>

#define MAXV (int)(1e2 + 5)

using namespace std;

int G[MAXV];
int GT[MAXV];
int V;
bool visit[MAXV];

int dfs(int u){
	visit[u] = true;
	if(!G[u])return u;
	return dfs(G[u]);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie( 0 );
	cout.tie(0);

	cin >> V;

	for(int i = 1;i <= V;i ++){
		int a, b;
		cin >> a >> b;
		GT[i] = a;
		G[i] = b;
	}

	int prev = -1;

	for(int i = 1;i <= V;i ++){
		if(!visit[i] && !GT[i]){

			if(prev != -1){
				G[prev] = i;
				GT[i] = prev;
			}
			prev = dfs(i);
		}
	}


	for(int i = 1;i <= V;i ++)
		cout << GT[i] << " " << G[i] << "\n";

	return 0;
}
/*
3
5 1	1

 */
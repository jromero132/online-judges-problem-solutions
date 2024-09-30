// Problem name: Dependency Problems
// Problem link: https://codeforces.com/gym/100497/problem/K
// Submission link: https://codeforces.com/gym/100497/submission/21235012

#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<cstring>
#include<string>
#include<cmath>
#include<stack>
#include<queue>
#include<cstdlib>
#include<map>
#include <bits/stdc++.h>

using namespace std;

#define DB( x ) cout << #x << " = " << x << endl;
#define LEFT(n) (2 * (n))
#define RIGHT(n) (2 * (n) + 1)
#define X real()
#define Y imag()

typedef long long ll;
typedef pair<int, int> node;
//typedef complex<double> P;

const ll INF = 1e9;
const double EPS = 1e-6;
const ll MOD = (ll)(1e5);
const ll MAXV = (ll)(1e5 + 1000);
const ll MAXE = (ll)(1e6 + 10);

map<int,int> start;
map<string,int> M;

int nodes = 1;

vector<int> G[1000000];
int in_degree[1000000];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string a;
	while(cin >> a){

		if(M[a] == 0)
			M[a] = nodes++;
		start[M[a]] = 1;
		string b;
		while(1){
			cin >> b;
			if(b == "0")
				break;
			if(M[b] == 0)
				M[b] = nodes++;

			G[M[b]].push_back(M[a]);

			in_degree[M[a]]++;

		}
	}

	int solve = 0;

	queue<int> Q;
	for(int i = 1 ; i < nodes;i++){
		if(in_degree[i] == 0 && start[i] == 1){
			Q.push(i);
		}
	}

	while(!Q.empty()){
		int cur = Q.front();
		Q.pop();
		solve++;
		for(int i = 0 ; i < G[cur].size(); i++){
			int ady = G[cur][i];
			in_degree[ady]--;
			if(in_degree[ady] == 0){
				Q.push(ady);
			}
		}
	}

	cout << solve << endl;
	return 0;
}
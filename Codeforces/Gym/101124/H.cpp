// Problem name: Kids' Play
// Problem link: https://codeforces.com/gym/101124/problem/H
// Submission link: https://codeforces.com/gym/101124/submission/21386437

#include<bits/stdc++.h>

#define PB push_back
#define remove erase
#define endl '\n'
#define FOR(IN,N) for(int I = IN;I < N;++I)
#define MAX

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<string, int> psi;


vector<int> sccs[100000 + 5];

vector<int> G[100000 + 5];

int low[100000 + 5];

int num[100000 + 5];

int numCounter;

int compCounter = 1;

int comp[100000 + 5];

stack<int> dfs_scc;
set<int> in_stack;

int E[100000 + 5];

int O[100000 + 5];

pii arr[100000 + 5];

int pos[100000 + 5];



void SCC(int u) {
	low[u] = num[u] = numCounter++;
	dfs_scc.push(u);
	in_stack.insert(u);

	for (int i = 0; i < G[u].size(); i++)
	{
		int v = G[u][i];

		if (num[v] == 0) {
			SCC(v);
		}

		if (in_stack.find(v) != in_stack.end()) {
			low[u] = min(low[u], low[v]);
		}
	}

	if (low[u] == num[u]) {
		//printf("SCC: ");
		int cont = 0;
		while (!dfs_scc.empty() && dfs_scc.top() != u)
		{
			int node = dfs_scc.top();

			in_stack.erase(dfs_scc.top()); dfs_scc.pop();

			comp[node] = compCounter;

			sccs[compCounter].push_back(node);

			pos[node] = cont++;
		}

		int root = dfs_scc.top();

		sccs[compCounter].push_back(root);

		comp[root] = compCounter++;

		in_stack.erase(dfs_scc.top()); dfs_scc.pop();

		pos[root] = cont;

	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n,k;
	scanf("%d%d",&k,&n);

	for(int i = 1 ; i <= k; i++)
	{
		int a,b;

		scanf("%d%d",&a,&b);

		arr[i] = pii(a,b);

		E[a] = i;

		O[b] = i;
	}

	for(int i = 1 ; i <= k; i++)
	{
		G[i].push_back(E[arr[i].second]);
	}

	for(int i = 1 ; i <= k ; i++)
	{
		if(comp[i] == 0)
			SCC(i);
	}

	for (int i = 0; i < n; i++)
	{
		int a;
		ll b;
		scanf("%d%lld",&a,&b);

		int cm = comp[a];

		b = b % sccs[cm].size();

		int solve = (pos[a] - b) % sccs[cm].size();
		solve += sccs[cm].size();
		solve = solve % sccs[cm].size();

		printf("%d\n",sccs[cm][solve]);
	}

	//cout << "debug" << endl;


}

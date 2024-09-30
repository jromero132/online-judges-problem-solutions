// Problem name: Election of Evil
// Problem link: https://codeforces.com/gym/101116/problem/E
// Submission link: https://codeforces.com/gym/101116/submission/21210706

#include <bits/stdc++.h>

using namespace std;

#define DB( x ) cout << #x << " = " << x << endl;
#define LEFT(n) (2 * (n))
#define RIGHT(n) (2 * (n) + 1)
#define X real()
#define Y imag()

typedef long long ll;
typedef pair<int, int> pii;
//typedef complex<double> P;

const ll INF = 1e9;
const double EPS = 1e-6;
const ll MOD = (ll)(1e5);
const ll MAXV = (ll)(1e5 + 10);
const ll MAXE = (ll)(1e6 + 10);


vector<int> G[1000000];

vector<int> starts;
vector<int> en;

vector<string> solve;

bool flags[1000000];

int node = 1;

int u,v,m;

map<string,int> N;
map<int,string> M;

void bfs(int node)
{
	queue<int> Q;
	Q.push(node);
	flags[node] = true;

	while (!Q.empty())
	{
		int cur = Q.front();Q.pop();

		for(int i = 0 ; i  < G[cur].size(); i++)
		{
			int ady = G[cur][i];
			if(!flags[ady])
			{
				flags[ady] = true;
				Q.push(ady);
			}

		}
	}
}

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--)
	{
		for(int i = 0 ; i < 1000000; i++)
		{
			G[i].clear();
			flags[i] = false;
		}
		N.clear();
		M.clear();
		node = 1;
		starts.clear();
		en.clear();
		solve.clear();

		cin >> u >> v >> m;

		for(int i = 0 ; i < u; i++)
		{
			string a;
			cin >> a;

			int p =0 ;
			if(N[a] == 0)
			{
				N[a] = node;
				p = node;
				node++;
			}
			else
				p = N[a];

			starts.push_back(p);
			M[p] = a;
		}

		for(int i = 0 ; i < v; i++)
		{
			string a;
			cin >> a;

			int p = 0;
			if(N[a] == 0)
			{
				N[a] = node;
				p = node;
				node++;
			}
			else
				p = N[a];

			en.push_back(p);
			M[p] = a;
		}

		for(int i = 0 ; i < m; i++)
		{
			string a,b;
			cin >> a >> b;

			int n1 = 0;
			int n2 = 0;

			if(N[a] == 0)
			{
				n1 = node++;
				N[a] = n1;
				M[n1] = a;
			}
			else
				n1 = N[a];

			if(N[b] == 0)
			{
				n2 = node++;
				N[b] = n2;
				M[n2] = b;
			}
			else
				n2 = N[b];

			G[n1].push_back(n2);
		}

		for(int i = 0 ; i < starts.size(); i++)
		{
			int no = starts[i];
			if(!flags[no])
			{
				bfs(no);
			}
		}

		for(int i = 0 ; i < en.size(); i++)
		{
			if(flags[en[i]])
			{
				string name = M[en[i]];
				solve.push_back(name);
			}
		}

		sort(solve.begin(),solve.end());

		for(int i = 0 ; i  < solve.size(); i++)
		{
			cout << solve[i] << " ";
		}
		cout << endl;

	}



}
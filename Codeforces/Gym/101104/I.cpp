// Problem name: Make it Manhattan
// Problem link: https://codeforces.com/gym/101104/problem/I
// Submission link: https://codeforces.com/gym/101104/submission/20972110

#include<bits/stdc++.h>

#define PB push_back
#define remove erase
#define endl '\n'
#define FOR(in,n) for(int i = in;i < n;i++)
#define MAX

using namespace std;

typedef long long ll;

typedef pair<int, int> pii;
typedef pair<int, ll> pll;
typedef pair<string, string> pss;
typedef vector<int> vi;

int t,n,d;

map<pii,int> M;

int x[1005];
int y[1005];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);


	cin >> t;
	while (t--)
	{
		cin >> d >> n;
		M.clear();
		memset(x,0,sizeof(x));
		memset(y,0,sizeof(y));
		for(int i = 0 ; i  < n; i++)
		{
			int a,b;
			cin >> a >> b;

			M[pii(((a%d) + d) % d,((b%d) + d) % d)]++;

			x[((a%d) + d) % d]++;
			y[((b%d) + d) % d]++;
		}

		int solve = 10000000;

		for(int i = 0 ; i < d; i++)
			for(int j = 0 ; j < d ; j++)
				solve = min(solve, (x[i] + y[j]) - M[pii(i,j)]);

		cout << solve << endl;
	}


}
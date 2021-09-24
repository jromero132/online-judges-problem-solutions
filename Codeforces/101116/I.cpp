// Problem name: Ingenious Lottery Tickets
// Problem link: https://codeforces.com/gym/101116/problem/I
// Submission link: https://codeforces.com/gym/101116/submission/21210038

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



int t,n;
int dp[55];

pii b[55];
vector<int> v;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while(t--)
	{
		cin >> n;
		memset(dp,0,sizeof(dp));
		for(int i = 0 ; i < n ; i++)
		{
			for(int j = 0 ; j < 6 ; j++)
			{
				int a;
				cin >> a;
				dp[a]++;
			}
		}
		for(int i = 0 ; i <= 50 ;i++)
		{
			b[i] = pii(0,0);
		}
		for(int i = 1; i <= 49; i++)
		{
			b[i] = pii(i,dp[i]);
		}

		for(int i = 1 ; i <= 49;i++)
		{
			for(int j = i; j <= 49; j++)
			{
				if(i == j)continue;
				if(b[i].second < b[j].second)
				{
					swap(b[i],b[j]);
				}
				else if(b[i].second == b[j].second)
				{
					if(b[j].first == 7)
						swap(b[i],b[j]);
					else if(b[j].first < b[i].first)
						swap(b[i],b[j]);
				}
			}
		}
		v.clear();
		for(int i = 1; i <= 6; i++)
		{
			v.push_back(b[i].first);
		}

		sort(v.begin(),v.end());
		for(int i = 0 ; i < v.size(); i++)
		{
			cout << v[i] << " ";
		}
		cout << endl;
	}


}
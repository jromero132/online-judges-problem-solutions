// Problem name: A multiplication game
// Problem link: https://codeforces.com/gym/101124/problem/M
// Submission link: https://codeforces.com/gym/101124/submission/21382983

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



bool Solve(ll n, ll a,ll b,int player)
{
	if(n >= a && n <= b){
		if(player == 1)
			return true;
		return false;
	}
	if(player == 1)
		return Solve(n,b + 1,b*2,0);
	else
		return Solve(n,b + 1,9*b,1);
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n = 1;
	while(scanf("%lld",&n)!=EOF)
	{
		//printf("%lld ",n);
		if(Solve(n,1,9,1))
			printf("Stan wins.\n");
		else
			printf("Ollie wins.\n");
		n++;
	}


	return 0;
}
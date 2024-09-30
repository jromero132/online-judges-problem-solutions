// Problem name: Insomnia
// Problem link: https://codeforces.com/gym/100090/problem/D
// Submission link: https://codeforces.com/gym/100090/submission/20993577

#include <bits/stdc++.h>

using namespace std;

#define DB( x ) cout << #x << " = " << x << endl;
#define LEFT(n) (2 * (n))
#define RIGHT(n) (2 * (n) + 1)
#define X real()
#define Y imag()

typedef long long ll;
typedef pair<int, int> node;
typedef complex<double> P;

const ll INF = 1e9;
const double EPS = 1e-6;
const ll MOD = (ll)(1e5);
const ll MAXV = (ll)(2e5 + 10);
const ll MAXE = (ll)(1e6 + 10);

ll dp[1000000 + 5];




int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);



	for(ll i = 2 ; i <= 1000000; i++)
	{

		dp[i]++;
		for(ll j = i + i; j <= 1000000; j += i)
		{
			dp[j] += dp[i];
		}

	}

	dp[1] = 1;

	int n;
	cin >> n;
	cout << dp[n] << endl;

	return 0;
}
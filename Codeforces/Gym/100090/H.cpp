// Problem name: Game with the Stones
// Problem link: https://codeforces.com/gym/100090/problem/H
// Submission link: https://codeforces.com/gym/100090/submission/20994428

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

int n;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);


	cin >> n;

	ll a;

	ll b = -1;

	for(int i = 0 ; i < n ; i++)
	{
		cin >> a;
		b = max(b,a);
	}

	if(__builtin_popcount(b + 1) == 1)
		cout << "Mike" << endl;
	else
		cout << "Constantine" << endl;


	return 0;
}
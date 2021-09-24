// Problem name: Bracket Sequence
// Problem link: https://codeforces.com/gym/100090/problem/K
// Submission link: https://codeforces.com/gym/100090/submission/20992475

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
const ll MAXV = (ll)(1e5 + 10);
const ll MAXE = (ll)(1e6 + 10);

long long a[200000 + 5];

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);


	string a;

	cin >> a;

	int b = 0;

	bool f = true;

	int l = a.size();

	for(int i = 0 ; i < l ; i++)
	{
		if(a[i] == ')')
			b--;
		else
			b++;

		if(b < 0)
			f = false;
	}

	if(b < 0 || !f)
		cout << "IMPOSSIBLE" << endl;
	else
	{
		cout << a;
		for(int i =0  ;i < b; i++)
			cout << ")";
	}

	cout << endl;


	return 0;
}
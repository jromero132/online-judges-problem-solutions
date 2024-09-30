// Problem name: The Last Wish
// Problem link: https://codeforces.com/gym/100090/problem/G
// Submission link: https://codeforces.com/gym/100090/submission/20994100

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


bool dp1[26];


bool first[26];

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);

	string a;

	cin >> a;

	bool ok = true;

	string solve = "";

	for(int i =  0 ; i < a.size(); i++)
	{
		dp1[a[i] - 'a'] = true;
	}

	for(int i = 0 ; i < a.size() && ok; i++)
	{
		if(!first[a[i] - 'a'])
		{
			solve += a[i];
			first[a[i] - 'a'] = true;
		}
		else
		{
			bool f = false;
			for(int i = 0 ; i < 26 && !f; i++)
			{
				if(!dp1[i])
				{
					dp1[i] = true;
					solve += i + 'a';
					f = true;
				}
			}

			if(!f)
				ok = false;
		}


	}

	if(!ok)
		cout << "IMPOSSIBLE" << endl;
	else
		cout << solve << endl;

	return 0;
}
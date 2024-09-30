// Problem name: UEFA Champions League
// Problem link: https://codeforces.com/gym/101778/problem/I
// Submission link: https://codeforces.com/gym/101778/submission/37287069

#include <bits/stdc++.h>

#define MAX ((int)501)
#define MAX_N ((int)7950)
#define MOD ((int)1000000001)
#define INF ((int)(1 << 30))
#define EPS ((double)1e-7)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define mod(x) (((x) % MOD + MOD) % MOD)
#define modS(x) ((x) % MOD)
#define DAD(x) ((x) >> 1)
#define LEFT(x) ((x) << 1)
#define RIGHT(x) ((x) << 1 | 1)
#define gcd(a, b) __gcd(a, b)
#define endl '\n'

using namespace std;

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldouble;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int test;
	cin >> test;

	for (int j = 1; j <= test; ++j)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		if (a + c > b + d || (a + c == b + d && c > b))
			cout << "1\n";
		else if (a + c < b + d || (a + c == b + d && b > c))
			cout << "2\n";
		else
			cout << "-1\n";
	}
	return 0;
}
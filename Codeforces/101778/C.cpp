// Problem name: Professor Agasa Lab
// Problem link: https://codeforces.com/gym/101778/problem/C
// Submission link: https://codeforces.com/gym/101778/submission/37288566

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

ll phi(ll n) {
	if (n == 0)
		return 0;
	ll ans = n;
	for (ll x = 2; x * x <= n; ++x)
		if (n % x == 0) {
			ans -= ans / x;
			while (n % x == 0)
				n /= x;
		}
	if (n > 1)
		ans -= ans / n;
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	ll n;
	for(cin >> t ; t-- ; ){
		cin >> n;
		cout << phi(n) * (n - 1) << endl;
	}
	return 0;
}
// Problem name: Delayed Work
// Problem link: https://codeforces.com/gym/101652/problem/Y
// Submission link: https://codeforces.com/gym/101652/submission/43586333

#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;

using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define DB( x ) cout << #x << " = " << x << endl;
#define LEFT(n) (2 * (n))
#define RIGHT(n) (2 * (n) + 1)

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, int> pii;
typedef pair<pii, int> piii;
typedef pair<pii, pii> piiii;
typedef pair<double, double> point;

const ll INF = 1e8;
const double EPS = 1e-6;
const ll MOD = (ll)(1000000007 );
const ll MAXV = (ll)(1e4 + 5);
const ll MAXE = (ll)(4e4 + 5);
const ll MAXLOG = (ll)(20);


int main(){
	ios_base::sync_with_stdio(0);cin.tie( 0 );
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	double k, p, x;

	cin >> k >> p >> x;

	double opt = sqrt((k * p) / x);

	ll M1, M2;
	M1 = (ll)floor(opt);
	M2 = (ll)ceil(opt);

	double ans1 = (k * p) / (double)M1 + (double)M1 * x;
	double ans2 = (k * p) / (double)M2 + (double)M2 * x;

	cout << setprecision(3) << fixed << min(ans1, ans2) << "\n";

	return 0;
}
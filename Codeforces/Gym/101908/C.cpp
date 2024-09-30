// Problem name: Pizza Cutter
// Problem link: https://codeforces.com/gym/101908/problem/C
// Submission link: https://codeforces.com/gym/101908/submission/44968516

#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define DB( x ) cout << #x << " = " << x << endl;
#define LEFT(n) (2 * (n))
#define RIGHT(n) (2 * (n) + 1)

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pii;
typedef pair<pii, int> piii;
typedef pair<pii, pii> piiii;
typedef pair<double, double> point;

const ll INF = 2e8;
const double EPS = 1e-6;
const ll MOD = (ll)(1000000007);
const ll MAXV = (ll)(4e3 + 5);
const ll MAXE = (ll)(4e4 + 10);
const ll MAXLOG = (ll)(20);

ll x, y;
ll h, v;

vector<pii> H, V;

int main(){
	ios_base::sync_with_stdio(0);cin.tie( 0 );

	cin >> x >> y;
	cin >> h >> v;

	for(int i = 0;i < h;i ++){
		ll y1, y2;
		cin >> y1 >> y2;
		H.push_back(pii{y1, y2});
	}
	for(int i = 0;i < v;i ++){
		ll x1, x2;
		cin >> x1 >> x2;
		V.push_back(pii{x1, x2});
	}

	ll ans = 1 + h * v + h + v;

	sort(H.begin(), H.end());
	sort(V.begin(), V.end());

	ordered_set<ll> S;

	for(int i = 0;i < H.size();i ++){
		ll left = H[i].second;
		ans += S.size() - S.order_of_key(left);
		S.insert(left);
	}
	S.clear();
	for(int i = 0;i < V.size();i ++){
		ll left = V[i].second;
		ans += S.size() - S.order_of_key(left);
		S.insert(left);
	}

	cout << ans << "\n";

	return 0;
}

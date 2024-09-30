// Problem name: Colonial Mansions
// Problem link: https://codeforces.com/gym/101962/problem/I
// Submission link: https://codeforces.com/gym/101962/submission/45149917

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
typedef pair<ll, pii> piii;
typedef pair<pii, pii> piiii;
typedef pair<double, double> point;

const ll INF =(1e16);
const double EPS = 1e-6;
//const ll MOD = (ll)(1e9 + 7);
const ll MAXV = (ll)(2e5 + 5);
const ll MAXE = (ll)(2e6 + 10);
const ll MAXLOG = (ll)(20);

int n, q;
ll H[MAXV];
ll seg_tree[MAXV * 4];

void update(int n, int s, int e, int p, ll x){
	if(s + 1 == e)
		seg_tree[n] = x;
	else{
		int m = (s + e) >> 1;
		if(p < m)
			update(LEFT(n), s, m, p, x);
		else
			update(RIGHT(n), m, e, p, x);
		seg_tree[n] = max(seg_tree[LEFT(n)], seg_tree[RIGHT(n)]);
	}
}

ll query(int n, int s, int e, int a, int b){
	if(s >= a && e <= b)
		return seg_tree[n];
	else if(e <= a || s >= b)
		return -INF;
	else{
		int m = (s + e) >> 1;
		ll l = query(LEFT(n), s, m, a, b);
		ll r = query(RIGHT(n), m, e, a, b);
		return max(l, r);
	}
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie( 0 );

	cin >> n >> q;

	for(int i = 0;i < n;i ++)
		cin >> H[i];

	for(int i = 0;i + 1 < n;i ++)
		update(1, 0, n - 1, i, abs(H[i] - H[i + 1]));

	while(q --){
		int t, pos;
		ll h;
		cin >> t >> pos >> h;
		pos --;
		if(t == 1){
			H[pos] = h;
			if(pos)
				update(1, 0, n - 1, pos - 1, abs(H[pos - 1] - H[pos]));
			if(pos < n - 1)
				update(1, 0, n - 1, pos, abs(H[pos] - H[pos + 1]));
		}
		else{
			ll ans = 0;
			int lo = 0, hi = pos, mi;
			while(lo + 2 < hi){
				mi = (lo + hi) >> 1;
				if(query(1, 0, n - 1, mi, pos) <= h)
					hi = mi;
				else
					lo = mi;
			}
			while(query(1, 0, n - 1, lo, pos) > h && lo < pos)lo ++;
			ans += pos - lo;

			lo = pos, hi = n - 1;
			while(lo + 2 < hi){
				mi = (lo + hi) >> 1;
				if(query(1, 0, n - 1, pos, mi) <= h)
					lo = mi;
				else
					hi = mi;
			}
			while(query(1, 0, n - 1, pos, hi) > h && hi > pos)hi --;
			ans += hi - pos;

			cout << ans + 1 << "\n";
		}
	}

	return 0;
}
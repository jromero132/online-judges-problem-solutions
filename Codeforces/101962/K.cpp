// Problem name: Rei do Cangaço
// Problem link: https://codeforces.com/gym/101962/problem/K
// Submission link: https://codeforces.com/gym/101962/submission/45148359

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

ll A[MAXV];
ll sum[MAXV];
ll ans[MAXV];
ll n;

int main(){
	ios_base::sync_with_stdio(0);cin.tie( 0 );

	cin >> n;
	for(int i = 1;i <= n;i ++){
		cin >> A[i];
		sum[i] = A[i];
		sum[i] += sum[i - 1];
	}
	sum[n + 1] = sum[n];

	for(int i = 1;i <= n;i ++){
		ll curr = i;
		ll turn = 1;

		while(curr <= n){
			ll adj = curr + 3 * turn;
			if(adj > n)
				adj = n + 1;
			ll s = sum[adj - 1] - sum[curr - 1];
			if(s > 0)
				ans[i] += s;
			curr = adj;
			turn ++;
		}
		cout << ans[i] << "\n";
	}

	return 0;
}
// Problem name: Powers of Two
// Problem link: https://codeforces.com/contest/702/problem/B
// Submission link: https://codeforces.com/contest/702/submission/45430627

#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;

using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//ordered_set<int>  s;
//cout << s.order_of_key(2) << endl; // the number of elements in the s less than 2
//cout << *s.find_by_order(0) << endl; // print the 0-th smallest number in s(0-based)

#define DB( x ) cout << #x << " = " << x << endl;
#define LEFT(n) (2 * (n))
#define RIGHT(n) (2 * (n) + 1)


typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<pii, pii> piiii;
typedef pair<double, double> point;

const ll MAXV = (ll)(2e5 + 10);
const ll MAXE = (ll)(2e6 + 10);
const ll MOD = (ll)(998244353);


typedef long double T;//tipo de las coordenadas long double, double, long long etc
typedef long double TT;//tipo de las magniutdes, precicion de angulos, distancias long double, double, etc
const TT INF = (1e30 + 10);
#define M_PI 3.1415926535897932384626433832795
#define NEXT(i) (((i) + 1) % n)
#define PREV(i) (((i) + n - 1) % n)
const TT EPS = (1e-12);

map<ll, ll> S;

int main(){
	ios_base::sync_with_stdio(0);cin.tie( 0 );

	int n;
	cin >> n;
	ll ans = 0;
	for(int i = 0;i < n;i ++){
		ll num;
		cin >> num;

		ll p = 1LL;
		for(int i = 0;i < 40;i ++){
			if(S.find(p - num) != S.end()){
				ans += S[p - num];
			}
			p *= 2LL;
		}

		S[num] ++;
	}

	cout << ans << "\n";

	return 0;
}
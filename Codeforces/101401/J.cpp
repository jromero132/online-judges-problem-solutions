// Problem name: Jackaroo
// Problem link: https://codeforces.com/gym/101401/problem/J
// Submission link: https://codeforces.com/gym/101401/submission/43705565

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
typedef pair<ll, ll> pii;
typedef pair<pii, int> piii;
typedef pair<pii, pii> piiii;
typedef pair<double, double> point;

const ll INF = 1e16;
const double EPS = 1e-6;
const ll MOD = (ll)(1000000007 );
const ll MAXV = (ll)(2e5 + 5);
const ll MAXE = (ll)(4e4 + 5);
const ll MAXLOG = (ll)(20);

ll n;

int main(){
	cin.sync_with_stdio( 0 );cin.tie( 0 );

	cin >> n;

	ll sum = 0;

	for(int i = 0;i < n;i ++){
		ll num;
		cin >> num;
		sum += num - 1LL;
	}

	sum += (n * (n + 1LL)) / 2LL;

	if(sum % 7LL == 0)
		cout << "yes\n";
	else
		cout << "no\n";

	return 0;
}
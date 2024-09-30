// Problem name: Forbidden Zero
// Problem link: https://codeforces.com/gym/101652/problem/Z
// Submission link: https://codeforces.com/gym/101652/submission/43585811

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

	ll n;

	cin >> n;
	n ++;
	while(1){
		ll aux = n;

		bool ok =true;
		while(aux){
			if(aux % 10LL == 0){
				ok = false;
				break;
			}
			aux /= 10LL;
		}
		if(ok){
			cout << n << "\n";
			return 0;
		}
		n ++;
	}

	return 0;
}
// Problem name: Unloaded Die
// Problem link: https://codeforces.com/gym/101652/problem/U
// Submission link: https://codeforces.com/gym/101652/submission/43588688

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

const ll INF = 1e16;
const double EPS = 1e-6;
const ll MOD = (ll)(1000000007 );
const ll MAXV = (ll)(1e4 + 5);
const ll MAXE = (ll)(4e4 + 5);
const ll MAXLOG = (ll)(20);

double V[10];
double new_label[10];

double calc(int x){
	double sum = 0.0;
	for(int i = 0;i < 6;i ++){
		if(i == x)continue;
		sum += ((double)(i + 1) * V[i]);
	}
	return (3.5 - sum) / V[x];
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie( 0 );
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);


	for(int i = 0;i < 6;i ++)
		cin >> V[i];

	double ans = INF;

	for(int i = 0;i < 6;i ++){
		new_label[i] = calc(i);
		ans = min(ans, abs(new_label[i] - (double)(i + 1)));
	}

	cout << setprecision(3) << fixed << ans << "\n";

	return 0;
}
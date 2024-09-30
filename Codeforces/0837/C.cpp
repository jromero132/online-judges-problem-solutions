// Problem name: Two Seals
// Problem link: https://codeforces.com/contest/837/problem/C
// Submission link: https://codeforces.com/contest/837/submission/43745212

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
const ll MAXV = (ll)(2e4 + 5);
const ll MAXE = (ll)(4e4 + 5);
const ll MAXLOG = (ll)(20);

int h, n, m;
int rect[105][2];
int ans;

int solve(int x1, int y1, int x2, int y2){
	int aux = 0;
	if(x1 <= n && y1 <= m){
		aux += x1 * y1;
		if((x2 <= n - x1 && y2 <= m) || (y2 <= m - y1 && x2 <= n)){
			aux += x2 * y2;
			return aux;
		}
	}
	return 0;
}

int main(){
	cin.sync_with_stdio( 0 );cin.tie( 0 );

	cin >> h >> n >> m;

	for(int i = 0;i < h;i ++){
		cin >> rect[i][0] >> rect[i][1];
	}

	for(int i = 0;i < h;i ++)
		for(int j = 0;j < h;j ++){
			if(i == j)continue;
			ans = max(ans, solve(rect[i][0], rect[i][1], rect[j][0], rect[j][1]));
			ans = max(ans, solve(rect[i][0], rect[i][1], rect[j][1], rect[j][0]));
			ans = max(ans, solve(rect[i][1], rect[i][0], rect[j][0], rect[j][1]));
			ans = max(ans, solve(rect[i][1], rect[i][0], rect[j][1], rect[j][0]));
		}

	cout << ans << "\n";
	return 0;
}
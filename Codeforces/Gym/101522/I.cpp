// Problem name: Inverted Signs
// Problem link: https://codeforces.com/gym/101522/problem/I
// Submission link: https://codeforces.com/gym/101522/submission/44088793

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

const ll MAXV = (ll)(2e6 + 10);
const ll MAXE = (ll)(2e6 + 10);
const ll INF = (ll)(1e16 + 10);
const double EPS = (1e-9);

int n;
ll A[MAXV];

bool cmp(pii a, pii b){
	return -a.first + a.second < -b.first + b.second;
}

int sig(ll x){
	if(x >= 0)
		return 1;
	else
		return -1;
}

int main(){
	cin.sync_with_stdio( 0 );cin.tie( 0 );

	ll sum = 0;
	cin >> n;
	vector <pii> dif;

	for(int i = 0;i < n;i ++){
		cin >> A[i];
		if(i){
			sum += abs(A[i] - A[i - 1]);
			if(sig(A[i]) != sig(A[i - 1]))
				dif.push_back({abs(A[i]) + abs(A[i - 1]), abs(abs(A[i]) - abs(A[i - 1]))});
		}

	}

	if(dif.size() == 0){
		cout << sum << "\n";
		return 0;
	}

	sort(dif.begin(), dif.end(), cmp);

	sum += (-dif[0].first + dif[0].second);
	if(dif.size() >= 2)
		sum += (-dif[1].first + dif[1].second);

	cout << sum << "\n";

	return 0;
}
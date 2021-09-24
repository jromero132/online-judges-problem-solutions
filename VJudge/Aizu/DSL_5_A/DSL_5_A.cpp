// Problem name: The Maximum Number of Customers
// Problem link: https://vjudge.net/problem/Aizu-DSL_5_A
// Submission link: https://vjudge.net/solution/12785686

#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define F first
#define S second
#define endl '\n'

using namespace std;

typedef pair<int, int> pii;

vector<pii> customer;

bool cmp(pii a, pii b){
	return a.F != b.F ? a.F < b.F : a.S < b.S;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, t, ans = 0, now = 0, e, l;
	cin >> n >> t;
	for(int i = 0 ; i < n ; i++){
		cin >> e >> l;
		customer.pb(mp(e, 1));
		customer.pb(mp(l, -1));
	}
	sort(customer.begin(), customer.end(), cmp);
	l = customer.size();
	for(int i = 0 ; i < l ; i++){
		now += customer[ i ].S;
		ans = max(ans, now);
	}
	cout << ans << endl;
	return 0;
}
// Problem name: Hotels Along the Croatian Coast
// Problem link: https://vjudge.net/problem/SPOJ-HOTELS
// Submission link: https://vjudge.net/solution/16130958

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

typedef long long ll;

int lower_bound(vector<ll> &sum, ll m, int left, int r){
	int middle, right = r;
	while(left < right){
		middle = (left + right) >> 1;
		if(sum[ r ] - sum[ middle - 1 ] <= m)
			right = middle;
		else
			left = middle + 1;
	}
	return left;
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);

#ifdef JoseA132
	freopen("01.in", "r", stdin);
#endif

	int n;
	ll m, ans = 0LL;
	cin >> n >> m;
	vector<ll> num(n), sum(n + 1, 0LL);
	for(int i = 0 ; i < n ; ++i){
		cin >> num[ i ];
		sum[ i + 1 ] = sum[ i ] + num[ i ];
		ans = max(ans, sum[ i + 1 ] - sum[ lower_bound(sum, m, 1, i + 1) - 1 ]);
	}
	cout << ans << endl;
	return 0;
}
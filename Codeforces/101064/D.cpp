// Problem name: Black Hills golden jewels 
// Problem link: https://codeforces.com/gym/101064/problem/D
// Submission link: https://codeforces.com/gym/101064/submission/45256775

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

typedef long long ll;

ll f(vector<ll> &v, ll c){
	ll ans = 0;
	for(int i = 1 ; i < v.size() && v[ i ] <= c ; ++i){
		auto p = upper_bound(v.begin(), v.begin() + i, c - v[ i ]);
		if(p == v.begin())
			break;
		ans += p - v.begin();
	}
	return ans;
}

ll bsearch(vector<ll> &v, ll k){
	ll left = 0, right = 2e9, middle;
	while(left < right){
		middle = (left + right) >> 1LL;
		if(f(v, middle) >= k)
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

	ll n, k;
	cin >> n >> k;
	vector<ll> v(n);
	for(auto &x : v)
		cin >> x;
	sort(v.begin(), v.end());
	cout << bsearch(v, k) << endl;
	return 0;
}
// Problem name: B - EvenOdd
// Problem link: https://matcomgrader.com/problem/9209/evenodd/
// Submission link: https://matcomgrader.com/submission/118001/

#include <iostream>

#define MOD (int)(1e9 + 7)
#define mod(x) (((x) % MOD + MOD) % MOD)

using namespace std;

typedef long long ll;

int f(ll n){
	int ans = 0;
	while(n > 1){
		if(n & 1)
			n++;
		else
			n >>= 1LL;
		ans++;
	}
	return ans;
}

ll solve(ll l, ll r){
	if(l > r)
		return 0;
	if(l == r)
		return f(l);
	if(!(l & 1))
		return mod(f(l) + solve(++l, r));
	if(r & 1)
		return mod(f(r) + solve(l, --r));
	return mod(mod(solve((l + 1) >> 1LL, r >> 1LL) << 1LL) + (3 * (r - l + 1) >> 1LL) - (l == 1LL ? 2 : 0));
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll l, r;
	cin >> l >> r;
	cout << solve(l, r);
	return 0;
}
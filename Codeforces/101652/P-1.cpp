// Problem name: Fear Factoring
// Problem link: https://codeforces.com/gym/101652/problem/P
// Submission link: https://codeforces.com/gym/101652/submission/43703836

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

typedef long long ll;

inline ll divisors(ll a, ll b, ll k){
	return b / k - (a - 1) / k;
}

inline ll interval_sum(ll a, ll b){
	return ((b - a + 1) * (b + a)) >> 1;
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);

#ifdef JoseA132
	freopen("01.in", "r", stdin);
#endif

	ll a, b, last, ans = 0LL;
	cin >> a >> b, last = (ll)sqrt(b);
	for(ll i = 1 ; i <= last ; ++i)
		ans += i * divisors(a, b, i) + interval_sum(max(last + 1, (a + i - 1) / i), max(last, b / i));
	cout << ans << endl;
	return 0;
}
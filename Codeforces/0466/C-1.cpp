// Problem name: Number of Ways
// Problem link: https://codeforces.com/contest/466/problem/C
// Submission link: https://codeforces.com/contest/466/submission/43585560

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);

#ifdef JoseA132
	freopen("01.in", "r", stdin);
#endif

	int n;
	cin >> n;
	ll s = 0LL, now = 0LL, ans = 0LL;
	vector<ll> num(n), sum(n + 1, 0);
	for(auto &v : num)
		cin >> v, s += v;
	if(s % 3){
		cout << 0 << endl;
		return 0;
	}
	s /= 3;
	for(int i = n ; --i >= 0 ; now += num[ i ], sum[ i ] = sum[ i + 1 ] + (now == s));
	now = 0LL;
	for(int i = 0 ; i < n - 2 ; ++i){
		now += num[ i ];
		if(now == s)
			ans += sum[ i + 2 ];
	}
	cout << ans << endl;
	return 0;
}
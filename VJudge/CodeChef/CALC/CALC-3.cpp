// Problem name: Calculator
// Problem link: https://vjudge.net/problem/CodeChef-CALC
// Submission link: https://vjudge.net/solution/16636882

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

typedef long long ll;

ll f(ll n, ll b, ll x){
	return (n - x * b) * x;
}

ll bsearch(int n, int b){
	ll l = 0, r = n / b, m;
	while(l < r){
		m = (l + r) >> 1;
		if(f(n, b, m) > f(n, b, m + 1))
			r = m;
		else
			l = m + 1;
	}
	return f(n, b, l);
}

ll tsearch(int n, int b){
	ll l = 0, r = n / b, m1, m2;
	while(l + 2 < r){
		m1 = l + (r - l) / 3;
		m2 = r - (r - l) / 3;
		if(f(n, b, m1) > f(n, b, m2))
			r = m2;
		else
			l = m1;
	}
	ll ans = 0;
	for( ; l <= r ; ans = max(ans, f(n, b, l++)));
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);

#ifdef JoseA132
	freopen("01.in", "r", stdin);
#endif

	int t;
	for(cin >> t ; t-- ; ){
		int n, b;
		cin >> n >> b;
		cout << tsearch(n, b) << endl;
	}
	return 0;
}
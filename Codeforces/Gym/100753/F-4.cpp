// Problem name: Divisions
// Problem link: https://codeforces.com/gym/100753/problem/F
// Submission link: https://codeforces.com/gym/100753/submission/43797412

#include <bits/stdc++.h>

#define gcd __gcd
#define pb push_back
#define endl '\n'

using namespace std;

typedef long long ll;

template<typename T1, typename T2, typename T3>
T1 mul(T1 a, T2 b, T3 m){
	T1 ans = 0;
	for( ; b ; b >>= 1){
		if(b & 1)
			ans = (ans + a) % m;
		a = (a << 1) % m;
	}
	return ans;
}


template<typename T1, typename T2, typename T3>
T1 pow(T1 n, T2 p, T3 m){
	T1 ans = 1;
	for( ; p ; p >>= 1){
		if(p & 1)
			ans = mul(ans, n, m);
		n = mul(n, n, m);
	}
	return ans;
}

bool is_witness(ll a, ll n, ll s, ll d){
	ll x = pow(a, d, n);
	if(x == 1 || x == n - 1)
		return 0;
	for(int i = 0 ; i < s - 1 ; ++i){
		x = mul(x, x, n);
		if(x == 1)
			return 1;
		if(x == n - 1)
			return 0;
	}
	return 1;
}

bool miller_rabin(ll n){
	if(~n & 1)
		return n == 2;
	if(n <= 3)
		return n == 3;
	int s = 0;
	ll d = n - 1;
	while(~d & 1)
		++s, d >>= 1;
	vector<ll> test = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 31, 37, 41 };
	for(ll p : test){
		if(p >= n)
			break;
		if(is_witness(p, n, s, d))
			return 0;
	}
	return 1;
}

ll pollard_rho(ll n){
	if(n <= 1)
		return 1 - ((n < 0) << 1);
	if(~n & 1)
		return 2;
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	while(1){
		ll x = uniform_int_distribution<ll>(0, n - 1)(rng), y = x, c = uniform_int_distribution<ll>(0, n - 1)(rng);
		for(int i = 1, k = 2 ; ; ++i){
			x = mul(x, x, n) - c - 1;
			if(x < 0)
				x += n;
			ll d = gcd(max(x, y) - min(x, y), n);
			if(d == n)
				break;
			if(d != 1)
				return d;
			if(i == k){
				y = x;
				k <<= 1;
			}
		}
	}
	return 0;
}

vector<ll> factorize(ll n){
	vector<ll> fact;
	queue<ll> q;
	for(q.push(n) ; !q.empty() ; q.pop()){
		n = q.front();
		if(miller_rabin(n)){
			fact.pb(n);
			continue;
		}
		ll f = pollard_rho(n);
		q.push(f), q.push(n / f);
	}
	return fact;
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);

#ifdef JoseA132
	freopen("01.in", "r", stdin);
#endif

	ll n, ans = 1, now = 0, last;
	cin >> n;
	if(n == 1){
		cout << 1 << endl;
		return 0;
	}
	vector<ll> fact = factorize(n);
	sort(fact.begin(), fact.end());
	last = fact[ 0 ];
	for(auto f : fact){
		if(f == last)
			++now;
		else
			ans *= (now + 1), last = f, now = 1;
	}
	ans *= (now + 1);
	cout << ans << endl;
	return 0;
}
// Problem name: Divisions
// Problem link: https://vjudge.net/problem/Gym-100753F
// Submission link: https://vjudge.net/solution/33031634

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

template<typename T>
T madd(T a, T b, T mod){
	T s = a - mod + b;
	return s + (s < 0 ? mod : 0);
}

template<typename T>
T bmul(T a, T b, T mod){
	T ans = 0;
	for(a %= mod, b %= mod ; b > 0 ; b >>= 1){
		if(b & 1)
			ans = madd(ans, a, mod);
		a = madd(a, a, mod);
	}
	return ans;
}

template<typename T1, typename T2>
T1 mbpow(T1 a, T2 b, T1 mod, T1 init = 1){
	T1 ans = init % mod;
	for(a %= mod ; b > 0 ; b >>= 1){
		if(b & 1)
			ans = bmul(ans, a, mod);
		a = bmul(a, a, mod);
	}
	return ans;
}

template<typename T>
bool miller_rabin(const T n){
	if(~n & 1)
		return n == 2;
	if(n <= 3)
		return n == 3;

	auto is_witness = [](T a, T n, int s, T d){
		T x = mbpow(a, d, n);
		if(x == 1 || x == n - 1)
			return false;
		for(int r = 1 ; r < s ; ++r){
			x = bmul(x, x, n);
			if(x == n - 1)
				return false;
		}
		return true;
	};

	int s = 0;
	T d = n - 1;
	while(~d & 1)
		++s, d >>= 1;

	const vector<T> test = { 2, 3, 5, 7, 11, 13, 17, 19, 23 };
	for(T p : test){
		if(p == n)
			break;
		if(is_witness(p, n, s, d))
			return false;
	}
	return true;
}

template<typename T, typename R = mt19937>
T pollard_rho(const T n, R rng = mt19937(chrono::steady_clock::now().time_since_epoch().count())){
	if(n <= 1)
		return n < 0 ? -1 : 1;
	if(~n & 1)
		return 2;

	while(true){
		T x = uniform_int_distribution<T>(0, n - 1)(rng), y = x, c = uniform_int_distribution<T>(1, n - 1)(rng);
		while(true){
			x = madd(bmul(x, x, n), c, n);
			y = madd(bmul(y, y, n), c, n);
			y = madd(bmul(y, y, n), c, n);
			T d = __gcd(max(x, y) - min(x, y), n);
			if(d == n)
				break;
			if(d != 1)
				return d;
		}
	}
}

template<typename T>
vector<T> factorize(T n){
	if(n == (T)1)
		return vector<T>{ 1 };
	T f;
	vector<T> fact;
	for(queue<T> q({ n }) ; !q.empty() ; q.pop()){
		n = q.front();
		if(miller_rabin(n))
			fact.push_back(n);
		else{
			f = pollard_rho(n);
			q.push(f);
			q.push(n / f);
		}
	}
	sort(fact.begin(), fact.end());
	return fact;
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	ll n;
	cin >> n;
	vector<ll> fact = factorize(n);
	int ans = 1;
	for(int left = 0, right = 0 ; left < fact.size() ; left = right){
		while(++right < fact.size() && fact[ right ] == fact[ left ]);
		ans *= (right - left + 1);
	}
	cout << ans - (n == 1) << endl;
	return 0;
}
// Problem name: Petr and a Combination Lock
// Problem link: https://vjudge.net/problem/CodeForces-1097B
// Submission link: https://vjudge.net/solution/32947212

#include <bits/stdc++.h>

#define popcount __builtin_popcount

using namespace std;

template<typename T>
T bitmask_solve(int n, const function<T(int)> &f, T initial_value = 0, const function<T(T, T)> &update = max<T>){
	T ans = initial_value;
	for(int mask = 1 << n ; --mask >= 0 ; ans = update(ans, f(mask)));
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n, l, r, x;
	cin >> n;
	vector<int> a(n);
	for(int &x : a)
		cin >> x;

	auto f = [&a, n](int mask){
		int angle = 0;
		for(int k = 0 ; k < n ; ++k)
			angle += (mask & (1 << k) ? 1 : -1) * a[ k ];
		return (angle % 360 + 360) % 360 == 0;
	};

	auto update = [](bool a, bool b){
		return a || b;
	};

	cout << (bitmask_solve<bool>(n, f, false, update) ? "YES" : "NO") << endl;
	return 0;
}
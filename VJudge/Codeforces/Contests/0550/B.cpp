// Problem name: Preparing Olympiad
// Problem link: https://vjudge.net/problem/CodeForces-550B
// Submission link: https://vjudge.net/solution/32947154

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
	cin >> n >> l >> r >> x;
	vector<int> c(n);
	for(int &x : c)
		cin >> x;

	auto f = [&c, n, l, r, x](int mask){
		if(popcount(mask) < 2)
			return 0;
		int min_c = 1000000, max_c = 1, difficult = 0;
		for(int k = 0 ; k < n ; ++k)
			if(mask & (1 << k))
				min_c = min(min_c, c[ k ]), max_c = max(max_c, c[ k ]), difficult += c[ k ];

		return difficult < l || difficult > r || max_c - min_c < x ? 0 : 1;
	};

	auto update = [](int a, int b){
		return a + b;
	};

	cout << bitmask_solve<int>(n, f, 0, update) << endl;
	return 0;
}
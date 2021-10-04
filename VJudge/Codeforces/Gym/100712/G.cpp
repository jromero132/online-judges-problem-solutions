// Problem name: Heavy Coins
// Problem link: https://vjudge.net/problem/Gym-100712G
// Submission link: https://vjudge.net/solution/32989673

#include <bits/stdc++.h>

#define popcount __builtin_popcount

using namespace std;

template<typename T>
T bitmask_solve(int n, const function<T(int)> &f, T initial_value, const function<T(T, T)> &update = [](T a, T b){ return max<T>(a, b); }){
	T ans = initial_value;
	for(int mask = 1 << n ; --mask >= 0 ; ans = update(ans, f(mask)));
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	const int INF = 1001;

	int t;
	for(cin >> t ; t-- ; ){
		int n, s;
		cin >> n >> s;
		vector<int> v(n);
		for(int &x : v)
			cin >> x;

		auto f = [n, s, &v](int mask){
			int m = INF, sum = 0;
			for(int i = 0 ; i < n ; ++i)
				if(mask & (1 << i))
					sum += v[ i ], m = min(m, v[ i ]);
			return sum < s || sum - m >= s ? 0 : popcount(mask);
		};

		cout << bitmask_solve<int>(n, f, 0) << endl;
	}
	return 0;
}
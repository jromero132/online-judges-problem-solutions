// Problem name: ORXOR
// Problem link: https://vjudge.net/problem/AtCoder-abc197_c
// Submission link: https://vjudge.net/solution/32986164

#include <bits/stdc++.h>

using namespace std;

template<typename T>
T bitmask_solve(int n, const function<T(int)> &f, T initial_value, const function<T(T, T)> &update = [](T a, T b){ return max(a, b); }){
	T ans = initial_value;
	for(int mask = 1 << n ; --mask >= 0 ; ans = update(ans, f(mask)));
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	const int INF = 1 << 30;

	int n;
	cin >> n;
	vector<int> v(n);
	for(auto &x : v)
		cin >> x;
	
	auto f = [n, &v](int mask){
		int ans = 0, cur= 0;
		for(int i = 0 ; i < n ; ++i){
			cur |= v[ i ];
			if(mask & (1 << i))
				ans ^= cur, cur = 0;
		}
		return ans ^ cur;
	};

	cout << bitmask_solve<int>(n, f, INF, [](int a, int b){ return min(a, b); }) << endl;
	return 0;
}
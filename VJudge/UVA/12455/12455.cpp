// Problem name: Bars
// Problem link: https://vjudge.net/problem/UVA-12455
// Submission link: https://vjudge.net/solution/32987738

#include <bits/stdc++.h>

using namespace std;

template<typename T>
T bitmask_solve(int n, const function<T(int)> &f, T initial_value, const function<T(T, T)> &update = [](T a, T b){ return max<T>(a, b); }){
	T ans = initial_value;
	for(int mask = 1 << n ; --mask >= 0 ; ans = update(ans, f(mask)));
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;
	for(cin >> t ; t-- ; ){
		int n, p;
		cin >> n >> p;
		vector<int> v(p);
		for(int &x : v)
			cin >> x;

		auto f = [n, p, &v](int mask){
			int sum = 0;
			for(int i = 0 ; i < p ; ++i)
				if(mask & (1 << i))
					sum += v[ i ];
			return n == sum;
		};

		cout << (bitmask_solve<bool>(p, f, false, [](bool a, bool b){ return a || b; }) ? "YES" : "NO") << endl;
	}
	return 0;
}
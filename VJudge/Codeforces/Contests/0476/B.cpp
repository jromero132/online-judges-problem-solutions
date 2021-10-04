// Problem name: Dreamoon and WiFi
// Problem link: https://vjudge.net/problem/CodeForces-476B
// Submission link: https://vjudge.net/solution/32987550

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

	string s1, s2;
	cin >> s1 >> s2;
	int p1 = 0, p2 = 0, n = 0;
	for(int i = 0 ; i < s1.length() ; ++i){
		p1 += (s1[ i ] == '+' ? 1 : -1);
		if(s2[ i ] == '?')
			++n;
		else
			p2 += (s2[ i ] == '+' ? 1 : -1);
	}

	auto f = [p1, p2, n](int mask){
		int val = 0;
		for(int i = 0 ; i < n ; ++i)
			val += (mask & (1 << i) ? 1 : -1);
		return p1 == p2 + val;
	};

	cout << setprecision(12) << fixed << (double)bitmask_solve<int>(n, f, 0, [](int a, int b){ return a + b; }) / (1 << n) << endl;
	return 0;
}
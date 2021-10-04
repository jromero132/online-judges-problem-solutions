// Problem name: Easy Longest Common Subsequence
// Problem link: https://vjudge.net/problem/SPOJ-EELCS
// Submission link: https://vjudge.net/solution/32985128

#include <bits/stdc++.h>

#define popcount __builtin_popcount

using namespace std;

template<typename T>
void bitmask_solve(int n, const function<T(int)> &f){
	for(int mask = 1 << n ; --mask >= 0 ; f(mask));
}

template<typename T>
T bitmask_solve(int n, const function<T(int)> &f, T initial_value, const function<T(T, T)> &update = [](T a, T b){ return max(a, b); }){
	T ans = initial_value;
	for(int mask = 1 << n ; --mask >= 0 ; ans = update(ans, f(mask)));
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	string s1, s2;
	cin >> s1 >> s2;
	
	auto f1 = [&s1, &s2](int mask1){
		int b = popcount(mask1);
		auto f2 = [mask1, b, &s1, &s2](int mask2){
			if(b != popcount(mask2))
				return 0;
			for(int i = 0, j = 0, k = 0 ; k < b ; ++i, ++j, ++k){
				while((mask1 & (1 << i)) == 0)
					++i;
				while((mask2 & (1 << j)) == 0)
					++j;
				if(s1[ i ] != s2[ j ])
					return 0;
			}
			return b;
		};
		return bitmask_solve<int>(s2.length(), f2, 0);
	};
	cout << bitmask_solve<int>(s1.length(), f1, 0) << endl;
	return 0;
}
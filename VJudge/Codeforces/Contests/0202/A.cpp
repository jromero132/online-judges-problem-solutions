// Problem name: LLPS
// Problem link: https://vjudge.net/problem/CodeForces-202A
// Submission link: https://vjudge.net/solution/32986304

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

	string s;
	cin >> s;

	auto f = [&s](int mask) -> string{
		string sub;
		for(int i = 0 ; i < s.length() ; ++i)
			if(mask & (1 << i))
				sub += s[ i ];
		for(int i = 0, j = sub.length() - 1 ; i < j ; ++i, --j)
			if(sub[ i ] != sub[ j ])
				return "";
		return sub;
	};

	cout << bitmask_solve<string>(s.length(), f, "", [](string a, string b){ return max(a, b); }) << endl;
	return 0;
}
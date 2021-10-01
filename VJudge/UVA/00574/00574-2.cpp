// Problem name: Sum It Up
// Problem link: https://vjudge.net/problem/UVA-574
// Submission link: https://vjudge.net/solution/32955422

#include <bits/stdc++.h>

using namespace std;

template<typename T>
void bitmask_solve(int n, const function<void(int)> &f){
	for(int mask = 1 << n ; --mask >= 0 ; f(mask));
}

template<typename T>
T bitmask_solve(int n, const function<T(int)> &f, T initial_value = 0, const function<T(T, T)> &update = max<T>){
	T ans = initial_value;
	for(int mask = 1 << n ; --mask >= 0 ; ans = update(ans, f(mask)));
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	for(int t, n ; cin >> t >> n && n ; ){
		vector<int> v(n);
		for(int &x : v)
			cin >> x;

		auto cmp = [](const vector<int> &v1, const vector<int> &v2){
			for(int i = 0 ; i < v1.size() && i < v2.size() ; ++i)
				if(v1[ i ] != v2[ i ])
					return v1[ i ] > v2[ i ];
			return v1.size() > v2.size();
		};
		set<vector<int>, decltype(cmp)> sol(cmp);

		auto f = [n, t, &v, &sol](int mask){
			vector<int> cur;
			int sum = 0;
			for(int k = 0 ; k < n ; ++k)
				if(mask & (1 << k))
					cur.push_back(v[ k ]), sum += v[ k ];
			if(sum == t){
				sort(cur.begin(), cur.end(), [](int a, int b){ return b < a; });
				if(sol.find(cur) == sol.end())
					sol.insert(cur);
			}
			return vector<int>();
		};

		bitmask_solve<void>(n, f);

		cout << "Sums of " << t << ":" << endl;
		if(sol.size() == 0)
			cout << "NONE" << endl;
		for(auto s : sol){
			cout << s[ 0 ];
			for(int i = 1 ; i < s.size() ; cout << '+' << s[ i++ ]);
			cout << endl;
		}
	}
	return 0;
}
// Problem name: The Brand New Function
// Problem link: https://vjudge.net/problem/CodeForces-244C
// Submission link: https://vjudge.net/solution/33000251

#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	const int size = 32;

	int n;
	cin >> n;
	set<int> ans, s1, s2;
	for(int x ; n-- ; swap(s1, s2), s2.clear()){
		cin >> x;
		ans.insert(x);
		s2.insert(x);
		for(int it : s1)
			ans.insert(it | x), s2.insert(it | x);
	}
	cout << ans.size() << endl;
	return 0;
}
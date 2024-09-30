// Problem name: Dawid and Bags of Candies
// Problem link: https://vjudge.net/problem/CodeForces-1230A
// Submission link: https://vjudge.net/solution/32946368

#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	vector<int> a(4);
	for(auto &x : a)
		cin >> x;
	sort(a.begin(), a.end());
	cout << (a[ 0 ] + a[ 3 ] == a[ 1 ] + a[ 2 ] || a[ 0 ] + a [ 1 ] + a[ 2 ] == a[ 3 ] ? "YES" : "NO") << endl;
	return 0;
}
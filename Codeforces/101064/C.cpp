// Problem name: Cahokia ruins
// Problem link: https://codeforces.com/gym/101064/problem/C
// Submission link: https://codeforces.com/gym/101064/submission/45255759

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);

#ifdef JoseA132
	freopen("01.in", "r", stdin);
#endif

	int n, h, sum = 0;
	cin >> n >> h;
	vector<int> v1(n), v2(n);
	for(auto &x : v1)
		cin >> x;
	for(int i = 0 ; i < n ; ++i)
		cin >> v2[ i ], sum = max(sum, v1[ i ] + v2[ i ]);
	cout << (double)(h - sum) / 2.0 << endl;
	return 0;
}
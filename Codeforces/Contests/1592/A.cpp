// Problem name: Gamer Hemose
// Problem link: https://codeforces.com/contest/1592/problem/A
// Submission link: https://codeforces.com/contest/1592/submission/130669248

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;
	for(cin >> t ; t-- ; ){
		int n, h;
		cin >> n >> h;
		vector<int> v(n);
		for(int &x : v)
			cin >> x;
		sort(v.begin(), v.end());
		int sum = v[ v.size() - 2 ] + v[ v.size() - 1 ];
		int ans = 2 * (h / sum);
		h %= sum;
		if(h > 0)
			++ans, h -= v[ v.size() - 1 ];
		if(h > 0)
			++ans;
		cout << ans << endl;
	}
	return 0;
}
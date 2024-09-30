// Problem name: Incredible Chess
// Problem link: https://vjudge.net/problem/LightOJ-1186
// Submission link: https://vjudge.net/solution/32878292

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	for(int k = 1 ; k <= t ; ++k){
		int n, ans = 0;
		cin >> n;
		vector<int> w(n);
		for(int &x : w)
			cin >> x;
		for(int i = 0, x ; i < n ; ++i){
			cin >> x;
			ans ^= x - w[ i ] - 1;
		}
		cout << "Case " << k << ": " << (ans ? "white" : "black") << " wins" << endl;
	}
}
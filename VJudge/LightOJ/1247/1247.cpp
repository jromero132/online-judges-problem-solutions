// Problem name: Matrix Game
// Problem link: https://vjudge.net/problem/LightOJ-1247
// Submission link: https://vjudge.net/solution/32878263

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	for(int k = 1 ; k <= t ; ++k){
		int n, m;
		cin >> n >> m;
		ll ans = 0;
		for(int sum = 0 ; n-- ; sum = 0){
			for(int i = 0, x ; i < m ; ++i)
				cin >> x, sum += x;
			ans ^= sum;
		}
		cout << "Case " << k << ": " << (ans ? "Alice" : "Bob") << endl;
	}
}
// Problem name: Left Right
// Problem link: https://vjudge.net/problem/LightOJ-1192
// Submission link: https://vjudge.net/solution/32878238

#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	for(int k = 1 ; k <= t ; ++k){
		int n, ans = 0;
		cin >> n;
		for(int a, b ; n-- ; )
			cin >> a >> b, ans ^= (b - a - 1);
		cout << "Case " << k << ": " << (ans ? "Alice" : "Bob") << endl;
	}
}
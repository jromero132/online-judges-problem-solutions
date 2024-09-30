// Problem name: Brush (I)
// Problem link: https://vjudge.net/problem/LightOJ-1015
// Submission link: https://vjudge.net/solution/32878201

#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	for(int k = 1 ; k <= t ; ++k){
		int n, sum = 0;
		cin >> n;
		for(int x ; n-- ; )
			cin >> x, sum += max(0, x);
		cout << "Case " << k << ": " << sum << endl;
	}
}
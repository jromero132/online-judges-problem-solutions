// Problem name: Opposite Task
// Problem link: https://vjudge.net/problem/LightOJ-1001
// Submission link: https://vjudge.net/solution/32877674

#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t, n;
	for(cin >> t ; t-- ; ){
		cin >> n;
		cout << min(n, 10) << ' ' << max(0, n - 10) << endl;
	}
}
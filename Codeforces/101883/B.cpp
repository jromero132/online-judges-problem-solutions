// Problem name: Racetrack
// Problem link: https://codeforces.com/gym/101883/problem/B
// Submission link: https://codeforces.com/gym/101883/submission/43081667

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);

	int a, b;
	cin >> a >> b;
	cout << (a / __gcd(a, b)) * b << endl;
	return 0;
}
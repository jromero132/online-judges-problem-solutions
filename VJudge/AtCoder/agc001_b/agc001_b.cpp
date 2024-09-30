// Problem name: Mysterious Light
// Problem link: https://vjudge.net/problem/AtCoder-agc001_b
// Submission link: https://vjudge.net/solution/12820852

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll n, x;
	cin >> n >> x;
	cout << 3 * (n - __gcd(n, x)) << endl;
	return 0;
}
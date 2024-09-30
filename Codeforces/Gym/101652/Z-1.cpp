// Problem name: Forbidden Zero
// Problem link: https://codeforces.com/gym/101652/problem/Z
// Submission link: https://codeforces.com/gym/101652/submission/43703359

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);

#ifdef JoseA132
	freopen("01.in", "r", stdin);
#endif

	int n, ans = 0, p = 1;
	cin >> n, ++n;
	while(n){
		ans += p * max(1, n % 10);
		n /= 10;
		p *= 10;
	}
	cout << ans << endl;
	return 0;
}
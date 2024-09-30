// Problem name: Smiley Faces (A)
// Problem link: https://codeforces.com/gym/101401/problem/A
// Submission link: https://codeforces.com/gym/101401/submission/43704044

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);

#ifdef JoseA132
	freopen("01.in", "r", stdin);
#endif

	int a, b, c, ans = 0;
	cin >> a >> b >> c;
	ans = min(b, c);
	b -= ans, c -= ans;
	if(c)
		ans += min(a >> 1, c);
	cout << ans << endl;
	return 0;
}
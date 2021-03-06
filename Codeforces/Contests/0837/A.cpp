// Problem name: Text Volume
// Problem link: https://codeforces.com/contest/837/problem/A
// Submission link: https://codeforces.com/contest/837/submission/43744313

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);

#ifdef JoseA132
	freopen("01.in", "r", stdin);
#endif

	int n, ans = 0;
	cin >> n;
	string s;
	while(cin >> s){
		int now = 0;
		for(int i = 0 ; s[ i ] ; ++i)
			now += (s[ i ] >= 65 && s[ i ] <= 90);
		ans = max(ans, now);
	}
	cout << ans << endl;
	return 0;
}
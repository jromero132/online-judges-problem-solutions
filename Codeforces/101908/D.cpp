// Problem name: Unraveling Monty Hall
// Problem link: https://codeforces.com/gym/101908/problem/D
// Submission link: https://codeforces.com/gym/101908/submission/44965961

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
	for(int i = 0, x ; i < n ; ++i){
		cin >> x;
		ans += (x != 1);
	}
	cout << ans << endl;
	return 0;
}
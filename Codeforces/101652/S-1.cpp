// Problem name: Purple Rain
// Problem link: https://codeforces.com/gym/101652/problem/S
// Submission link: https://codeforces.com/gym/101652/submission/43703668

#include <bits/stdc++.h>

#define F first
#define S second
#define endl '\n'

using namespace std;

typedef pair<int, int> pii;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);

#ifdef JoseA132
	freopen("01.in", "r", stdin);
#endif

	string s;
	cin >> s;
	int ans1 = 0, ans2 = 0, now1 = 0, now2 = 0, l1 = 0, l2 = 0;
	pii p1, p2;
	for(int i = 0 ; s[ i ] ; ++i){
		now1 += (s[ i ] == 'B' ? 1 : -1);
		now2 += (s[ i ] == 'B' ? -1 : 1);
		if(now1 > ans1)
			ans1 = now1, p1 = { l1, i };
		if(now2 > ans2)
			ans2 = now2, p2 = { l2, i };
		if(now1 == -1)
			now1 = 0, l1 = i + 1;
		if(now2 == -1)
			now2 = 0, l2 = i + 1;
	}
	if(ans1 > ans2 || (ans1 == ans2 && p1 < p2))
		cout << ++p1.F << ' ' << ++p1.S << endl;
	else
		cout << ++p2.F << ' ' << ++p2.S << endl;
	return 0;
}
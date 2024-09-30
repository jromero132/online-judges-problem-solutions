// Problem name: Fafa and the Gates
// Problem link: https://codeforces.com/contest/935/problem/B
// Submission link: https://codeforces.com/contest/935/submission/35482955

#include <bits/stdc++.h>

#define MAX ((int)32000)
#define endl '\n'

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, ans = 0, x = 0, y = 0;
	string s;
	cin >> n >> s;
	for(int i = 0 ; i < n ; i++){
		if(s[ i ] == 'U')
			y++;
		else
			x++;
		if(x == y && i < n - 1 && s[ i ] == s[ i + 1 ])
			ans++;
	}
	cout << ans << endl;
	return 0;
}
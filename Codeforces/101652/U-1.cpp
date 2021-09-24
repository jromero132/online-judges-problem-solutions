// Problem name: Unloaded Die
// Problem link: https://codeforces.com/gym/101652/problem/U
// Submission link: https://codeforces.com/gym/101652/submission/43703436

#include <bits/stdc++.h>

#define EPS ((double)1e-7)
#define endl '\n'

using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);

#ifdef JoseA132
	freopen("01.in", "r", stdin);
#endif

	double ans = 1e9, sum = 0;
	vector<double> side(6);
	for(int i = 0 ; i < side.size() ; ++i)
		cin >> side[ i ], sum += (i + 1) * side[ i ];
	for(int i = 0 ; i < side.size() ; ++i){
		if(side[ i ] < EPS)
			continue;
		ans = min(ans, fabs(i + 1 - (3.5 - sum + (i + 1) * side[ i ]) / side[ i ]));
	}
	cout << setprecision(3) << fixed << ans << endl;
	return 0;
}
// Problem name: Smiley Faces (B)
// Problem link: https://codeforces.com/gym/101401/problem/B
// Submission link: https://codeforces.com/gym/101401/submission/43704368

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);

#ifdef JoseA132
	freopen("01.in", "r", stdin);
#endif

	string s;
	cin >> s;
	vector<int> DP1(s.length(), 0), DP2(s.length(), 0);
	for(int i = 1, j = s.length() - 2 ; s[ i ] ; ++i, --j)
		DP1[ i ] = DP1[ i - 1 ] + (s[ i - 1 ] == '(' && s[ i ] == ':'), DP2[ j ] = DP2[ j + 1 ] + (s[ j ] == ':' && s[ j + 1 ] == ')');
	int ans = max(DP1[ s.length() - 1 ], DP2[ 0 ]);
	for(int i = 1 ; s[ i ] ; ++i)
		ans = max(ans, DP2[ i ] + DP1[ i - 1 ] + (s[ 0 ] == ':' && s[ i ] == ')'));
	cout << ans << endl;
	return 0;
}
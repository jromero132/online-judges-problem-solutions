// Problem name: Chess Tourney
// Problem link: https://codeforces.com/contest/845/problem/A
// Submission link: https://codeforces.com/contest/845/submission/43117082

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);

	#ifdef JoseA132
		freopen("01.in", "r", stdin);
	#else
	#endif

	int n;
	cin >> n;
	vector<int> num(n << 1);
	for(auto &i : num)
		cin >> i;
	sort(num.begin(), num.end());
	cout << (num[ n ] > num[ n - 1 ] ? "YES" : "NO") << endl;
	return 0;
}
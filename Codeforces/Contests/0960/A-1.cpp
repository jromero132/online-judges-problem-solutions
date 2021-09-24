// Problem name: Check the string
// Problem link: https://codeforces.com/contest/960/problem/A
// Submission link: https://codeforces.com/contest/960/submission/43801704

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);

#ifdef JoseA132
	freopen("01.in", "r", stdin);
#endif

	string s;
	int a = 0, b = 0, c = 0;
	cin >> s;
	for(int i = 0 ; s[ i ] ; ++i)
		a += (s[ i ] == 'a'), b += (s[ i ] == 'b'), c += (s[ i ] == 'c');
	if(a == 0 || b == 0 || (c != a && c != b)){
		cout << "NO" << endl;
		return 0;
	}
	cout << (s == string(a, 'a') + string(b, 'b') + string(c, 'c') ? "YES" : "NO") << endl;
	return 0;
}
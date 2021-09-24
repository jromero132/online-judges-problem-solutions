// Problem name: Transformation
// Problem link: https://vjudge.net/problem/Aizu-ITP1_9_D
// Submission link: https://vjudge.net/solution/12786185

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

string s;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string ope;
	cin >> s;
	int q, a, b;
	for(cin >> q ; q-- ;){
		cin >> ope >> a >> b;
		if(ope == "replace")
			cin >> ope, s = s.substr(0, a) + ope + (b == s.length() ? "" : s.substr(b + 1));
		else if(ope == "reverse")
			reverse(s.begin() + a, s.begin() + min((int)s.length(), b + 1));
		else
			cout << s.substr(a, b - a + 1) << endl;
	}
	return 0;
}
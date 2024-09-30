// Problem name: MaratonIME goes to the karaoke
// Problem link: https://codeforces.com/gym/101744/problem/K
// Submission link: https://codeforces.com/gym/101744/submission/43082820

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);

	string s;
	cin >> s;
	int cnt = 1;
	for(int i = 1 ; i <= s.length() ; i++){
		while(s[ i ] == s[ i - 1 ])
			++cnt, ++i;
		cout << s[ i - 1 ] << cnt;
		cnt = 1;
	}
	cout << endl;
	return 0;
}
// Problem name: Bark to Unlock
// Problem link: https://codeforces.com/contest/868/problem/A
// Submission link: https://codeforces.com/contest/868/submission/43802780

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
	int n;
	cin >> n;
	vector<string> ss(n);
	for(int i = 0 ; i < n ; ++i){
		cin >> ss[ i ];
		if(ss[ i ].find(s, 0) != string::npos){
			cout << "YES" << endl;
			return 0;
		}
		for(int j = 0 ; j <= i ; ++j){
			string s1 = ss[ i ] + ss[ j ], s2 = ss[ j ] + ss[ i ];
			if(s1.find(s, 0) != string::npos || s2.find(s, 0) != string::npos){
				cout << "YES" << endl;
				return 0;
			}
		}
	}
	cout << "NO" << endl;
	return 0;
}
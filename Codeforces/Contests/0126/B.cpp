// Problem name: Password
// Problem link: https://codeforces.com/contest/126/problem/B
// Submission link: https://codeforces.com/contest/126/submission/44560588

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

vector<int> pi_function(const string &s){
	int n = s.length();
	vector<int> pi(n);
	for(int i = 1, k = 0 ; i < n ; ++i){
		while(k && s[ i ] != s[ k ])
			k = pi[ k - 1 ];
		k += (s[ i ] == s[ k ]);
		pi[ i ] = k;
	}
	return pi;
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);

#ifdef JoseA132
	freopen("01.in", "r", stdin);
#endif

	string s;
	cin >> s;
	vector<int> pi = pi_function(s);
	int n = s.length() - 1;
	if(!pi[ n ]){
		cout << "Just a legend" << endl;
		return 0;
	}
	for(int i = 1 ; i < n ; ++i)
		if(pi[ i ] >= pi[ n ]){
			cout << s.substr(0, pi[ n ]) << endl;
			return 0;
		}
	if(!pi[ pi[ n ] - 1 ])
		cout << "Just a legend" << endl;
	else
		cout << s.substr(0, pi[ pi[ n ] - 1 ]) << endl;
	return 0;
}
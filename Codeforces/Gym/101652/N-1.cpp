// Problem name: Odd Palindrome
// Problem link: https://codeforces.com/gym/101652/problem/N
// Submission link: https://codeforces.com/gym/101652/submission/43703434

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

bool palindrome(string s, int l, int r){
	for( ; l < r ; ++l, --r)
		if(s[ l ] != s[ r ])
			return 0;
	return 1;
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);

#ifdef JoseA132
	freopen("01.in", "r", stdin);
#endif

	string s;
	cin >> s;
	for(int i = 0 ; i < s.length() ; ++i)
		for(int j = i + 1 ; j < s.length() ; j += 2)
			if(palindrome(s, i, j)){
				cout << "Or not." << endl;
				return 0;
			}
	cout << "Odd." << endl;
	return 0;
}
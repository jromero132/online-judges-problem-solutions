// Problem name: Pig Latin
// Problem link: https://codeforces.com/gym/101883/problem/C
// Submission link: https://codeforces.com/gym/101883/submission/43082172

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);

	int t;
	cin >> t;
	string s;
	getline(cin, s);
	while(t--){
		getline(cin, s);
		bool first = 1;
		for(int i = 0 ; s[ i ] ; i++){
			if(s[ i ] != ' '){
				string word = "";
				while(i < s.length() && s[ i ] != ' ')
					word += s[ i ], ++i;
				--i;

				word += (char)(word[ 0 ] + (first ? 32 : 0));
				word = word.substr(1);
				if(first)
					first = 0, word[ 0 ] -= 32;
				cout << word << "ay";
			}
			else
				cout << ' ';
		}
		cout << endl;
	}
	return 0;
}
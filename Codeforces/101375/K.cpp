// Problem name: MaratonIME bot
// Problem link: https://codeforces.com/gym/101375/problem/K
// Submission link: https://codeforces.com/gym/101375/submission/37114048

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    string s;
    bool sussu = 0;
    while(cin >> s)
        sussu |= (s == "Sussu");
    if(!sussu && s[ s.length() - 1 ] == '.' || s[ s.length() - 1 ] == '!')
        sussu = s.substr(0, s.length() - 1) == "Sussu";
    cout << (s[ s.length() - 1 ] == '?' ? "7" : (sussu ? "AI SUSSU!" : "O cara é bom!"));
	return 0;
}
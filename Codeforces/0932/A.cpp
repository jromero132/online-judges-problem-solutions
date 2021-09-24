// Problem name: Palindromic Supersequence
// Problem link: https://codeforces.com/contest/932/problem/A
// Submission link: https://codeforces.com/contest/932/submission/35297721

#include <bits/stdc++.h>

#define MAX ((int)300000)
#define pb push_back
#define mp make_pair
#define endl '\n'

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string s;
	cin >> s;
	cout << s;
	for(int i = s.length() ; --i >= 0 ; cout << s[ i ]);
	return 0;
}
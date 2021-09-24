// Problem name: Minimal string
// Problem link: https://codeforces.com/contest/797/problem/C
// Submission link: https://codeforces.com/contest/797/submission/44375377

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);

#ifdef JoseA132
	freopen("01.in", "r", stdin);
#endif

	string s, u = "";
	cin >> s;
	vector<int> m(s.length() + 1, s.length() - 1);
	for(int i = s.length() - 1 ; i >= 0 ; --i)
		m[ i ] = (s[ i ] <= s[ m[ i + 1 ] ] ? i : m[ i + 1 ]);
	stack<char> t;
	for(int i = 0 ; s[ i ] ; ){
		if(t.empty() || t.top() > s[ m[ i ] ]){
			for(int j = i ; j <= m[ i ] ; ++j)
				t.push(s[ j ]);
			i = m[ i ] + 1;
			continue;
		}
		u += t.top(), t.pop();
	}
	while(!t.empty())
		u += t.top(), t.pop();
	cout << u << endl;
	return 0;
}
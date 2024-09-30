// Problem name: MaratonIME plays Nim
// Problem link: https://codeforces.com/gym/101744/problem/C
// Submission link: https://codeforces.com/gym/101744/submission/43088590

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0);

	int p1, p2, a, b;
	cin >> p1 >> p2;
	while(p1 | p2){
		a = 1, b = 0;
		if(!p1){
			cout << 2 << ' ' << p2 << endl << flush;
			p2 = 0;
		}
		else if(!p2){
			cout << 1 << ' ' << p1 << endl << flush;
			p1 = 0;
		}
		else{
			cout << (p1 > p2 ? 1 : 2) << ' ' << abs(p1 - p2) << endl << flush;
			cin >> a >> b;
			p1 = p2 = min(p1, p2);
		}
		p1 -= (a == 1) * b;
		p2 -= (a == 2) * b;
	}
	return 0;
}
// Problem name: Star Arrangements
// Problem link: https://codeforces.com/gym/101652/problem/X
// Submission link: https://codeforces.com/gym/101652/submission/43703437

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);

#ifdef JoseA132
	freopen("01.in", "r", stdin);
#endif

	int s;
	cin >> s, cout << s << ":" << endl;
	for(int i = 2 ; i < s ; ++i){
		if(!((s - i) % (2 * i - 1)) || !(s % (2 * i - 1)))
			cout << i << ',' << i - 1 << endl;
		if(!(s % i))
			cout << i << ',' << i << endl;
	}
	return 0;
}
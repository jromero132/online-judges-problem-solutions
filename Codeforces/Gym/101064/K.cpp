// Problem name: Mount Rushmore and Birthdays
// Problem link: https://codeforces.com/gym/101064/problem/K
// Submission link: https://codeforces.com/gym/101064/submission/45256293

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

typedef long double ld;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);

#ifdef JoseA132
	freopen("01.in", "r", stdin);
#endif

	int n, k = 0;
	cin >> n;
	ld fact = 1, p = 1;
	for(ld prob = 0 ; prob <= (ld)0.5 ; ++k){
		p *= n;
		fact *= (n - k);
		prob = (ld)1 - fact / p;
	}
	cout << k << endl;
	return 0;
}
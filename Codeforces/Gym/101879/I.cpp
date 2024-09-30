// Problem name: A story about tea
// Problem link: https://codeforces.com/gym/101879/problem/I
// Submission link: https://codeforces.com/gym/101879/submission/45338764

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);

	int n, m;
	cin >> n >> m;
	if(m < (1 << n) - 1){
		cout << "N" << endl;
		return 0;
	}
	cout << 'Y' << endl;
	vector<char> peg = { 'A', 'B', 'C' };
	if(~n & 1)
		swap(peg[ 1 ], peg[ 2 ]);
	int q = m - (1 << n) + 1;
	while (q >= 2)
		cout << "A B" << endl << "B A" << endl, q -= 2;
	if(q & 1)
		cout << peg[ 0 ] << ' ' << peg[ 1 ] << endl << peg[ 1 ] << ' ' << peg[ 2 ] << endl;
	for(int m = (q + 1), last = (1 << n) - 1 ; m <= last ; ++m)
		cout << peg[ (m - (m & -m)) % 3 ] << ' ' << peg[ (m + (m & -m)) % 3 ] << endl;
	return 0;
}
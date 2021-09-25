// Problem name: Finite Encyclopedia of Integer Sequences
// Problem link: https://vjudge.net/problem/AtCoder-arc084_c
// Submission link: https://vjudge.net/solution/32883625

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int k, n;
	cin >> k >> n;
	if(k & 1){
		vector<int> seq(n, (k + 1) >> 1);
		int len = n - 1;
		for(int i = n >> 1 ; i > 0 ; --i){
			if(seq[ len ] == 1)
				seq[ len-- ] = k;
			else
				--seq[ len ], len = n - 1;
		}
		cout << seq[ 0 ];
		for(int i = 1 ; i <= len ; cout << ' ' << seq[ i++ ]);
	}
	else{
		cout << (k >> 1);
		while(--n)
			cout << ' ' << k;
	}
	return 0;
}
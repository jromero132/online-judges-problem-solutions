// Problem name: Hemose Shopping
// Problem link: https://codeforces.com/contest/1592/problem/B
// Submission link: https://codeforces.com/contest/1592/submission/130688026

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;
	for(cin >> t ; t-- ; ){
		int n, x;
		cin >> n >> x;
		vector<int> v(n);
		for(int i = 0 ; i < n ; ++i)
			cin >> v[ i ];
		if(2 * x <= n)
			cout << "YES" << endl;
		else{
			vector<int> w(n);
			copy(v.begin(), v.end(), w.begin());
			sort(w.begin(), w.end());
			bool ok = true;
			for(int left = n - x ; left < x ; ++left)
				ok &= v[ left ] == w[ left ];
			cout << (ok ? "YES" : "NO") << endl;
		}
	}
	return 0;
}
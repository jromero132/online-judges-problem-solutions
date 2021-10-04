// Problem name: Bored Bakry
// Problem link: https://codeforces.com/contest/1592/problem/E
// Submission link: https://codeforces.com/contest/1592/submission/130748820

#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	const int BITS = 20;

	int n;
	cin >> n;
	vector<int> a(n), prefix_xor(n + 1);
	for(int i = 0 ; i < n ; ++i)
		cin >> a[ i ], prefix_xor[ i + 1 ] = prefix_xor[ i ] ^ a[ i ];

	int ans = 0;
	for(int k = BITS - 1, mask = 1 << (BITS - 1) ; k >= 0 ; --k, mask >>= 1){
		vector<int> last(1 << (BITS - k), -1);
		for(int left = 0, right = 0 ; left < n ; left = ++right){
			while(right < n && (a[ right ] & mask))
				++right;
			for(int i = left ; i <= right ; ++i)
				last[ prefix_xor[ i ] >> k ] = i;
			for( ; left <= right ; ++left)
				ans = max(ans, last[ prefix_xor[ left ] >> k ] - left);
		}
	}
	cout << ans << endl;
	return 0;
}
// Problem name: Jollybee Tournament
// Problem link: https://vjudge.net/problem/UVA-1241
// Submission link: https://vjudge.net/solution/32998593

#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;
	for(cin >> t ; t-- ; ){
		int n, m, p = 0;
		cin >> n >> m;

		vector<bool> player(1 << n, 1);
		for(int x ; m-- ; )
			cin >> x, player[ x - 1 ] = 0;

		int ans = 0;
		for(int gap = 1 << n ; gap > 1 ; gap >>= 1){
			for(int i = 0 ; i < gap ; i += 2){
				ans += player[ i ] ^ player[ i + 1 ];
				player[ i >> 1 ] = player[ i ] | player[ i + 1 ];
			}
		}
		cout << ans << endl;
	}
	return 0;
}
// Problem name: Johnny and Another Rating Drop
// Problem link: https://vjudge.net/problem/CodeForces-1362C
// Submission link: https://vjudge.net/solution/32998807

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;
	for(cin >> t ; t-- ; ){
		ll n;
		cin >> n;
		ll ans = 0;
		for( ; n > 0 ; ans += n, n >>= 1);
		cout << ans << endl;
	}
	return 0;
}
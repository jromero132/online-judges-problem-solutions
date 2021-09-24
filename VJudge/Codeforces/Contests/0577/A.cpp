// Problem name: Multiplication Table
// Problem link: https://vjudge.net/problem/CodeForces-577A
// Submission link: https://vjudge.net/solution/16114192

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

#ifdef JoseA132
	freopen("01.in", "r", stdin);
#endif

	int n, m, ans = 0;
	cin >> n >> m;
	for(int i = 1 ; i <= n && (ll)i * i <= m ; ++i){
		if(m % i)
			continue;
		if(m <= (ll)n * i)
			ans += 1 + ((ll)i * i != m);
	}
	cout << ans << endl;
	return 0;
}
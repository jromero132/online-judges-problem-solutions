// Problem name: Kefa and First Steps
// Problem link: https://vjudge.net/problem/CodeForces-580A
// Submission link: https://vjudge.net/solution/16130511

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);

#ifdef JoseA132
	freopen("01.in", "r", stdin);
#endif

	int n, last = -1, ans = 0, now = 0;
	cin >> n;
	vector<int> num(n);
	for(auto &v : num){
		cin >> v;
		if(v >= last)
			++now;
		else
			ans = max(ans, now), now = 1;
		last = v;
	}
	cout << max(ans, now) << endl;
	return 0;
}
// Problem name: Conan and Agasa play a Card Game
// Problem link: https://codeforces.com/contest/914/problem/B
// Submission link: https://codeforces.com/contest/914/submission/44406131

#include <bits/stdc++.h>

#define pb push_back
#define endl '\n'

using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);

#ifdef JoseA132
	freopen("01.in", "r", stdin);
#endif

	int n;
	cin >> n;
	vector<int> v(n), p;
	for(auto &x : v)
		cin >> x;
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	int now = 0, last = 0;
	for(int i = 0 ; i < n ; ++i)
		if(v[ i ] == v[ last ])
			++now;
		else
			p.pb(now), now = 1, last = i;
	p.pb(now);
	for(int i = 0 ; i < p.size() ; ++i)
		if(p[ i ] & 1){
			cout << "Conan" << endl;
			return 0;
		}
	cout << "Agasa" << endl;
	return 0;
}
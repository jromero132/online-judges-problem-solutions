// Problem name: Qualification Rounds
// Problem link: https://codeforces.com/contest/868/problem/C
// Submission link: https://codeforces.com/contest/868/submission/43807432

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);

#ifdef JoseA132
	freopen("01.in", "r", stdin);
#endif

	int n, k;
	cin >> n >> k;
	set<int> s;
	for(int i = 0 ; i < n ; ++i){
		int now = 0;
		for(int j = 0, v ; j < k ; ++j)
			cin >> v, now |= (v << j);
		s.insert(now);
	}
	if(s.find(0) != s.end()){
		cout << "YES" << endl;
		return 0;
	}
	for(auto x : s){
		for(int mask = ~x & ((1 << k) - 1), submask = mask ; submask ; submask = mask & (submask - 1)){
			if(s.find(submask) != s.end()){
				cout << "YES" << endl;
				return 0;
			}
		}
	}
	cout << "NO" << endl;
	return 0;
}
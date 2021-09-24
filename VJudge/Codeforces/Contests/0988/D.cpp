// Problem name: Points and Powers of Two
// Problem link: https://vjudge.net/problem/CodeForces-988D
// Submission link: https://vjudge.net/solution/16116572

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);

#ifdef JoseA132
	freopen("01.in", "r", stdin);
#endif

	int n;
	cin >> n;
	vector<int> num(n);
	for(auto &v : num)
		cin >> v;
	sort(num.begin(), num.end());
	int ans = 1;
	pair<int, int> sol;
	set<int> s1;
	set<pair<int, int>> s2;
	ll lower = num[ 0 ];
	for(auto v : num){
		ll now;
		for(int p = 0 ; v - (1LL << p) >= lower ; ++p){
			now = v - (1LL << p);
			if(s1.find(now) == s1.end())
				continue;
			if(s2.find(make_pair(now, p)) == s2.end())
				ans = 2, sol = { now, v }, s2.insert({ v, p });
			else{
				cout << 3 << endl << v - ((1LL << p) << 1LL) << ' ' << v - (1LL << p) << ' ' << v << endl;
				return 0;
			}
		}
		s1.insert(v);
	}
	cout << ans << endl;
	if(--ans)
		cout << sol.first << ' ' << sol.second << endl;
	else
		cout << lower << endl;
	return 0;
}
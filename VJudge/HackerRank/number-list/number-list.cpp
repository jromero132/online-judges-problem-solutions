// Problem name: Number List
// Problem link: https://vjudge.net/problem/HackerRank-number-list
// Submission link: https://vjudge.net/solution/16637808

#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);

#ifdef JoseA132
	freopen("01.in", "r", stdin);
#endif

	int t;
	for(cin >> t ; t-- ; ){
		int n, k;
		cin >> n >> k;
		ll ans = 0;
		vector<int> v(n), left(n);
		stack<int> s;
		for(int i = 0 ; i < n ; ++i){
			cin >> v[ i ];
			for( ; !s.empty() && v[ s.top() ] <= v[ i ] ; s.pop());
			left[ i ] = i - (s.empty() ? -1 : s.top());
			s.push(i);
		}
		for( ; !s.empty() ; s.pop());
		for(int i = n - 1 ; i >= 0 ; --i){
			for( ; !s.empty() && v[ s.top() ] < v[ i ] ; s.pop());
			if(v[ i ] > k)
				ans += (ll)left[ i ] * ((s.empty() ? n : s.top()) - i);
			s.push(i);
		}
		cout << ans << endl;
	}
	return 0;
}
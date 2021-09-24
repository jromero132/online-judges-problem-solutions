// Problem name: Maximum Subsequence
// Problem link: https://codeforces.com/contest/888/problem/E
// Submission link: https://codeforces.com/contest/888/submission/37915842

#include <bits/stdc++.h>

#define push_back pb
#define endl '\n'

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, n1, n2;
    ll m, now, ans = 0;
    cin >> n >> m;
    vector<int> num(n);
    set<int> mod;
    set<int>::iterator it;
    for(auto &v : num)
    	cin >> v;
    n1 = n >> 1;
    n2 = n - n1;
    for(int mask = 0 ; mask <= (1 << n1) ; mask++){
    	now = 0;
    	for(int i = n1 ; --i >= 0 ; )
    		if((1 << i) & mask)
    			now = (now + num[ i ]) % m;
    	if(mod.find(now) == mod.end())
    		mod.insert(now);
    	ans = max(ans, now);
    }
    for(int mask = 0 ; mask <= (1 << n2) ; mask++){
		now = 0;
		for(int i = n2 ; --i >= 0 ; )
			if((1 << i) & mask)
				now = (now + num[ i + n1 ]) % m;
		ans = max(ans, now);
		it = mod.upper_bound(m - now - 1);
		if(--it != mod.begin()){
            ans = max(ans, now + (*it));
		}
	}
	cout << ans << endl;
    return 0;
}
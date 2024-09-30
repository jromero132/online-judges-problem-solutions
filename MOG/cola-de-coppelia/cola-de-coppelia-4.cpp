// Problem name: C - Cola de Coppelia
// Problem link: https://matcomgrader.com/problem/8/cola-de-coppelia/
// Submission link: https://matcomgrader.com/submission/123386/

#include <bits/stdc++.h>

#define mp make_pair
#define F first
#define S second
#define endl '\n'

using namespace std;

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    int n, v;
    ll ans = 0;
    cin >> n;
    stack< pair<int, ll> > s;
    for(int i = 0 ; i < n ; i++){
		cin >> v;
        while(!s.empty() && s.top().F < v)
            s.pop(), ans++;
		if(!s.empty()){
			if(s.top().F == v)
				ans += s.top().S, s.push(mp(v, s.top().S + 1LL));
            else
            	ans++, s.push(mp(v, 2LL));
		}
		else
			s.push(mp(v, 1LL));
    }
    cout << ans << endl;
	return 0;
}
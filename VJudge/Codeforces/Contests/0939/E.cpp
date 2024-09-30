// Problem name: Maximize!
// Problem link: https://vjudge.net/problem/CodeForces-939E
// Submission link: https://vjudge.net/solution/16636938

#include <bits/stdc++.h>

#define pb push_back
#define endl '\n'

using namespace std;

typedef long long ll;

double f(vector<ll> &sum, int last, int p){
	return last - ((double)last + sum[ p ]) / (p + 1);
}

double bsearch(vector<ll> &sum, int last){
	int n = sum.size() - 1, l = 0, r = n - 1, m;
	while(l < r){
		m = (l + r) >> 1;
		if(f(sum, last, m) > f(sum, last, m + 1))
			r = m;
		else
			l = m + 1;
	}
	return f(sum, last, l);
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);

#ifdef JoseA132
	freopen("01.in", "r", stdin);
#endif

	int q, last = 0;
	double ans = 0;
	vector<ll> sum(1, 0);
	for(cin >> q ; q-- ; ){
		int ope, v;
		cin >> ope;
		if(--ope)
			cout << setprecision(8) << fixed << ans << endl;
		else
			cin >> v, sum.pb(sum.back() + v), last = v, ans = bsearch(sum, last);
	}
	return 0;
}
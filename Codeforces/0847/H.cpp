// Problem name: Load Testing
// Problem link: https://codeforces.com/contest/847/problem/H
// Submission link: https://codeforces.com/contest/847/submission/30952817

#include <bits/stdc++.h>

#define MAXV (int)(1e5 + 5)
#define ll long long

const ll INF = (1e18 + 5);

using namespace std;

int n;

ll input[MAXV];
ll dpa[MAXV], dpb[MAXV];
ll suma[MAXV], sumb[MAXV];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie( 0 );
	cout.tie(0);

	cin >> n;

	for(int i = 1;i <= n;i ++)
		cin >> input[i];

	for(int i = 1;i <= n;i ++){
		dpa[i] = max(input[i], dpa[i - 1] + 1LL);
		suma[i] = dpa[i] - input[i];
		suma[i] += suma[i - 1];
	}

	for(int i = n;i >= 1;i --){
		dpb[i] = max(input[i], dpb[i + 1] + 1LL);
		sumb[i] = dpb[i] - input[i];
		sumb[i] += sumb[i + 1];
	}

	ll ans = INF;

	for(int i = 1;i <= n;i ++){
		ans = min(ans, suma[i - 1] + sumb[i + 1] + max(dpa[i], dpb[i]) - input[i]);
	}

	cout << ans << "\n";

	return 0;
}
/*
3
5 1	1

 */
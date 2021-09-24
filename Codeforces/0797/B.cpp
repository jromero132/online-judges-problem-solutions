// Problem name: Odd sum
// Problem link: https://codeforces.com/contest/797/problem/B
// Submission link: https://codeforces.com/contest/797/submission/44374986

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);

#ifdef JoseA132
	freopen("01.in", "r", stdin);
#endif

	int n, sum = 0, oddp = INT_MAX, oddn = INT_MIN;
	cin >> n;
	for(int i = 0 ; i < n ; ++i){
		int x;
		cin >> x;
		if(x > 0){
			sum += x;
			if(x & 1)
				oddp = min(oddp, x);
		}
		else if(x & 1)
			oddn = max(oddn, x);
	}
	if(~sum & 1)
		sum = max(oddp == INT_MAX ? INT_MIN : sum - oddp, oddn == INT_MIN ? INT_MIN : sum + oddn);
	cout << sum << endl;
	return 0;
}
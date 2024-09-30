// Problem name: Halfway
// Problem link: https://codeforces.com/gym/101652/problem/Q
// Submission link: https://codeforces.com/gym/101652/submission/43703659

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

typedef long long ll;

ll binary_search(ll n, ll left, ll right, ll target){
	ll middle;
	while(left < right){
		middle = (left + right) >> 1LL;
		if(target <= middle * n - ((middle * (middle + 1LL)) >> 1LL))
			right = middle;
		else
			left = middle + 1;
	}
	return left;
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);

#ifdef JoseA132
	freopen("01.in", "r", stdin);
#endif

	ll n;
	cin >> n;
	cout << binary_search(n, 1LL, n, (((n * (n - 1LL)) >> 1LL) + 1LL) >> 1LL) << endl;
	return 0;
}
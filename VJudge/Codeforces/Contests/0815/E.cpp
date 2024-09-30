// Problem name: Karen and Neighborhood
// Problem link: https://vjudge.net/problem/CodeForces-815E
// Submission link: https://vjudge.net/solution/13341201

#include <bits/stdc++.h>

#define mp make_pair
#define F first
#define S second
#define max(a, b, c) max(a, max(b, c))
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

map<ll, ll> onLeft, onRight;
pll onMiddle;

bool possible(ll n, ll k, ll limit){
	onLeft.clear();
	onRight.clear();
    onLeft[ 0LL ] = onRight[ 0LL ] = 0LL;
    onMiddle = mp(2LL, n - 1LL);
    ll maxInterval, leftLen, middleLen, rightLen, center;
    pll now;
    while(k){
        leftLen = onLeft.rbegin() -> F;
		middleLen = onMiddle.S - onMiddle.F + 1LL;
		rightLen = onRight.rbegin() -> F;
		maxInterval = max(leftLen, middleLen, rightLen);
		if(((leftLen + 1LL) >> 1LL) == ((maxInterval + 1LL) >> 1LL)){
			now = mp(onLeft.rbegin() -> F, onLeft.rbegin() -> S);
			if(k <= now.S)
				return 1;
			k -= now.S;
			onLeft[ (now.F - 1LL) >> 1LL ] += now.S;
			onLeft[ now.F >> 1LL ] += now.S;
			onLeft.erase(now.F);
		}
		else if(((middleLen + 1LL) >> 1LL) == ((maxInterval + 1LL) >> 1LL)){
			center = (onMiddle.F + onMiddle.S) >> 1LL;
			if(k == 1)
				return center <= limit;
			now = onMiddle;
			onMiddle = mp(0LL, -132LL);
            k--;
            if(center - 1LL <= limit)
                onLeft[ center - now.F ]++;
			else
				onMiddle = mp(now.F, center - 1);
			if(center >= limit)
				onRight[ now.S - center ]++;
			else
				onMiddle = mp(center + 1LL, now.S);
		}
		else{
			now = mp(onRight.rbegin() -> F, onRight.rbegin() -> S);
			if(k <= now.S)
				return 0;
			k -= now.S;
			onRight[ (now.F - 1LL) >> 1LL ] += now.S;
			onRight[ now.F >> 1LL ] += now.S;
			onRight.erase(now.F);
		}
    }
    return 0;
}

ll solve(ll n, ll k){
    ll left  = 2LL, right = n - 1LL, middle;
    while(left + 1 < right){
		middle = (left + right) >> 1LL;
        if(possible(n, k, middle))
            right = middle;
		else
			left = middle;
    }
    return right - (possible(n, k, right - 1LL) ? 1LL : 0LL);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll n, k;
	cin >> n >> k;
	cout << (k == 1LL ? 1LL : (k == 2LL ? n : solve(n, k - 2LL))) << endl;
	return 0;
}
// Problem name: Fake NP
// Problem link: https://codeforces.com/contest/805/problem/A
// Submission link: https://codeforces.com/contest/805/submission/27508509

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main ()
{
	ll l , r , ans = 0 ; 
	cin >> l >> r ; 
	for(ll i = 2 ; i <= 1e18 ;i++)
		ans += 1 , ans -= 1 ;
	if(l == r)
		cout << l ; 
	else
		cout << 2; 
}
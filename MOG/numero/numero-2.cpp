// Problem name: A - Número
// Problem link: https://matcomgrader.com/problem/4698/numero/
// Submission link: https://matcomgrader.com/submission/62254/

#include <bits/stdc++.h>

/* Name: Jose Ariel Romero
 * Class: ?
 * Problem: A - Número */

using namespace std;

const long long mod=1000000007;
long long eleva(long long a, long long n)
{
	long long res = 1;
	for(a %= mod; n; n >>= 1, a = a * a % mod)
		if(n & 1) res = res * a % mod;
	return res;
}

int main()
{
        cin.sync_with_stdio(false);
	cin.tie(0);
        cout.sync_with_stdio(false);
	cout.tie(0);
	long long k;
	cin>>k;
	cout<<(10*6*(eleva(10,28*(k-1)+27)-3+mod)%mod*eleva(29,mod-2)+6)%mod<<endl;
	return 0;
}
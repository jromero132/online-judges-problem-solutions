// Problem name: A - Número
// Problem link: https://matcomgrader.com/problem/4698/numero/
// Submission link: https://matcomgrader.com/submission/63584/

#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

const i64 MOD = 1000000007;

i64 fast_pow(i64 a, i64 n)
{
	i64 ans = 1;

	for(a %= MOD; n; n >>= 1, a = a * a % MOD)
		if(n & 1) ans = ans * a % MOD;

	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	i64 k;

	cin >> k;

	cout << (10*6*(fast_pow(10,28*(k-1)+27)-3+MOD)%MOD*fast_pow(29,MOD-2)+6)%MOD << endl;
	
	return 0;
}
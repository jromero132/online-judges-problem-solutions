// Problem name: Beautiful Divisors
// Problem link: https://codeforces.com/contest/893/problem/B
// Submission link: https://codeforces.com/contest/893/submission/32583229

#include <bits/stdc++.h>

#define MAX (int)(1e5 + 1)
#define MOD (int)(3)
#define mod(x) (((x) % MOD + MOD) % MOD)
#define endl '\n'

using namespace std;

bool check(int n){
	for(int k = 1 ; ; k++){
		if(((1 << k) - 1) * (1 << (k - 1)) > n)
			return 0;
		else if(((1 << k) - 1) * (1 << (k - 1)) == n)
			return 1;
	}
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	int n, m = 0;
	cin >> n;
	for(int i = 1 ; i * i <= n ; i++){
		if(!(n % i)){
			if(check(n / i))
				m = max(m, n / i);
			if(check(i))
				m = max(m, i);
		}
	}
	cout << m;
    return 0;
}
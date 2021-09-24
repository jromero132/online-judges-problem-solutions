// Problem name: Halfway
// Problem link: https://codeforces.com/gym/101652/problem/Q
// Submission link: https://codeforces.com/gym/101652/submission/43587171

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second



int main()
{
	//freopen("a.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(0);

	ll n;
	cin >> n;

	ll k = (n-1)*n/2, pos = (k+1)/2;

	ll b = 0, e = n;
	while (b < e)
	{
		ll p = (b+e)>>1;
		if (k-(n-p)*(n-p+1)/2 >= pos)
			e = p;
		else
			b = p+1;
	}

	cout << b-1 << "\n";

	return 0;
}
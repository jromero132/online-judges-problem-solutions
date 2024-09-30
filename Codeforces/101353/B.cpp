// Problem name: Max and Alexis Plan to Conquer the World
// Problem link: https://codeforces.com/gym/101353/problem/B
// Submission link: https://codeforces.com/gym/101353/submission/37262124

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ld Pow(ld a, int b)
{
	ld x = 1;
	for (; b > 0; b >>= 1)
	{
		if (b & 1) x = x * a;
		a = a * a;
	}
	return x;
}

int main()
{
	//freopen("a.txt", "r", stdin);
	ios_base::sync_with_stdio(false), cin.tie(NULL);

	int t;
	cin >> t;
	ull n, r, p;
	for (int j = 1; j <= t; ++j)
	{
		cin >> n >> r >> p;
		if (p <= n)
		{
			cout << "Case " << j << ": " << 0 << "\n";
			continue;
		}
		ld c = ((ld)(r+100)) / 100.0;
		ld x = ((ld)p)/n;
		int k = log(x) / log(c);
		cout << "Case " << j << ": " << k + (Pow(((ld)r+100)/100.0, k)*n < p) << "\n";
	}

    return 0;
}
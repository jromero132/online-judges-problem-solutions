// Problem name: Genta Game
// Problem link: https://codeforces.com/gym/101778/problem/H
// Submission link: https://codeforces.com/gym/101778/submission/37288429

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ll mod = 1e9+7;

ll Pow(ll a, ll b)
{
	ll x = 1;
	for (; b > 0; b >>= 1)
	{
		if (b & 1) x = x*a%mod;
		a = a*a%mod;
	}
	return x;
}

template<typename T>
struct ABI
{
    int n;
    vector<T> f;
    ABI(int n) : n(n), f(n + 1) {}

    T query(int b)
    {
        T ret = 0;
        for (; b; b -= b & -b)
            ret += f[b];
        return ret;
    }

    void update(int b, T c)
    {
        for (; b <= n; b += b & -b)
            f[b] += c;
    }
};

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL);

	int test;
	cin >> test;

	int p, n, k, ans; string s; char c;
	for (int j = 1; j <= test; ++j)
	{
	    ans = 0;
		cin >> n >> k >> s;
		ABI<ll> f(n+1);
		for (int p = 1; p <= n; ++p)
		{
			c = s[p-1];
			int u = s[p-1] == s[n-1-(p-1)];
			f.update(p, u - (f.query(p) - f.query(p-1)));
			int z = n-1-(p-1)+1;
			f.update(z, u - (f.query(z) - f.query(z-1)));
		}
		while (k--)
		{
			cin >> p >> c;
			s[p-1] = c;
			int u = s[p-1] == s[n-1-(p-1)];
			f.update(p, u - (f.query(p) - f.query(p-1)));
			int z = n-1-(p-1)+1;
			f.update(z, u - (f.query(z) - f.query(z-1)));
			ans += f.query(n) == n;
		}
		cout << ans << "\n";
	}

    return 0;
}
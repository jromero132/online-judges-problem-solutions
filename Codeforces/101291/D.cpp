// Problem name: Cameras
// Problem link: https://codeforces.com/gym/101291/problem/D
// Submission link: https://codeforces.com/gym/101291/submission/37239845

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

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
	//freopen("a.txt", "r", stdin);
	ios_base::sync_with_stdio(false), cin.tie(NULL);

	int n, k, r;
	cin >> n >> k >> r;
	ABI<ll> f(n);
	for (int i = 0, x; i < k; ++i)
	{
		cin >> x;
		f.update(x, 1);
	}

	int ans = 0;
	for (int i = r; i <= n; ++i)
	{
		int z = f.query(i) - f.query(i-r);
		if (z == 1)
		{
			++ans;
			f.update(i - (f.query(i)-f.query(i-1) > 0), 1);
		}
		if (z == 0)
			ans += 2, f.update(i, 1), f.update(i-1, 1);
	}

	cout << ans << "\n";

    return 0;
}
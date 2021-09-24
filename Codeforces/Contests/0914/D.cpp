// Problem name: Bash and a Tough Math Puzzle
// Problem link: https://codeforces.com/contest/914/problem/D
// Submission link: https://codeforces.com/contest/914/submission/44407221

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define __gcd gcd

inline int gcd(int a, int b) { a=abs(a), b=abs(b); while(b) swap(b, a%=b); return a; }

struct seg_tree
{
    int n;
    vector<int> a;

    seg_tree(int n) : n(n), a(2 * n) {}

    inline void update(int p, int v)
    {
        for (--p, a[p += n] = v; p >>= 1;)
            a[p] = __gcd(a[p<<1], a[p<<1|1]);
    }

    inline int query(int l, int r)
    {
        int g = 0;

        for (--l, --r, l += n, r += n; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1) g = __gcd(g, a[l++]);
            if (r & 1) g = __gcd(g, a[--r]);
        }

        return g;
    }
};

int main()
{
	//freopen("a.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(0);

	int n;
	cin >> n;
	vector<int> a(n+1);
	seg_tree st(n+1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		st.update(i, a[i]-a[i-1]);
	}

	int q;
	cin >> q;
	for (int t, l, r, x; q--; )
	{
		cin >> t >> l >> r;
		if (t == 2)
		{
			a[l] = r;
			st.update(l, a[l]-a[l-1]);
			if (l+1 <= n)
				st.update(l+1, a[l+1]-a[l]);
			continue;
		}

		cin >> x;

		if (a[l] % x != 0)
		{
			if (l == r || (a[l+1] % x == 0 && (l+2 > r || __gcd(a[l+1], st.query(l+2, r+1)) % x == 0)))
				cout << "YES\n";
			else
				cout << "NO\n";
			continue;
		}

		int b = l+1, e = r;
		while (b < e)
		{
			int m = (b+e+1)>>1;
			if (__gcd(a[l], st.query(l+1, m+1)) % x == 0)
				b = m;
			else
				e = m-1;
		}

		if (a[b] % x != 0)
			--b;

		if (b+2 > r || (a[b+2] % x == 0 && (b+3 > r || __gcd(a[b+2], st.query(b+3, r+1)) % x == 0)))
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}
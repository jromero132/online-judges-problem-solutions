// Problem name: Running a penitentiary
// Problem link: https://codeforces.com/gym/101879/problem/G
// Submission link: https://codeforces.com/gym/101879/submission/45337932

/*#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);

	int n, m;
	cin >> n >> m;
	if(m < (1 << n) - 1){
		cout << "N" << endl;
		return 0;
	}
	cout << 'Y' << endl;
	vector<char> peg = { 'A', 'B', 'C' };
	int q = m - (1 << n) + 1;
	for(int i = 2 ; i < q ; i += 2)
		cout << "A B" << endl << "B A" << endl;
	if(q & 1)
		cout << peg[ 0 ] << ' ' << peg[ 2 ] << endl;
	if(~n & 1)
		swap(peg[ 1 ], peg[ 2 ]);
	for(int m = 1, last = (1 << n) - 1 ; m <= last ; ++m)
		cout << peg[ (m - (m & -m)) % 3 ] << ' ' << peg[ (m + (m & -m)) % 3 ] << endl;
	return 0;
}*/

#include <bits/stdc++.h>

#define endl '\n'
#define S second
#define F first

using namespace std;

typedef long long ll;

struct segment_tree_max
{
    int n;
    vector<ll> a;

    segment_tree_max(int n) : n(n), a(2 * n, numeric_limits<ll>::min()) {}

    void update(int p, ll v)
    {
        for (a[p += n] = v; p /= 2;)
            a[p] = max(a[2 * p], a[2 * p + 1]);
    }

    ll query(int l, int r)
    {
        ll g = numeric_limits<ll>::min();

        for (l += n, r += n; l < r; l /= 2, r /= 2)
        {
            if (l & 1) g = max(g, a[l++]);
            if (r & 1) g = max(g, a[--r]);
        }

        return g;
    }
};

struct segment_tree_min
{
    int n;
    vector<ll> a;

    segment_tree_min(int n) : n(n), a(2 * n, numeric_limits<ll>::max()) {}

    void update(int p, ll v)
    {
        for (a[p += n] = v; p /= 2;)
            a[p] = min(a[2 * p], a[2 * p + 1]);
    }

    ll query(int l, int r)
    {
        ll g = numeric_limits<ll>::max();

        for (l += n, r += n; l < r; l /= 2, r /= 2)
        {
            if (l & 1) g = min(g, a[l++]);
            if (r & 1) g = min(g, a[--r]);
        }

        return g;
    }
};

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0);

	int n, q;
	cin >> n >> q;
	segment_tree_max mx(n);
	segment_tree_min mn(n);

	for (int i = 0, x, y; i < n; ++i)
	{
		cin >> x >> y;
		mx.update(i, x);
		mn.update(i, y);
	}

	char op;
	for (int i, l, r; q--; )
	{
		cin >> op;
		if (op == '?')
		{
			cin >> l >> r;
			--l;
			//cout << mn.query(l, r) << endl;
			//cout << mx.query(l, r) << endl;
			cout << max(0LL, mn.query(l, r)-mx.query(l, r)+1) << "\n";
			continue;
		}
		cin >> i >> l >> r;
		--i;
		mx.update(i, l);
		mn.update(i, r);
	}

	return 0;
}
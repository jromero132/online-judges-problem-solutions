// Problem name: Renanzinho and His Toys
// Problem link: https://codeforces.com/gym/101962/problem/F
// Submission link: https://codeforces.com/gym/101962/submission/45153270

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define F first
#define S second

const ll inf = numeric_limits<ll>::max();

struct seg_tree
{
	int n;
	vector<ll> st, lz;
	seg_tree(int n) : n(n), st(4*n, -inf), lz(4*n) {}
	void push(int cur, int b, int e, int m)
	{
		if (lz[cur] != 0)
		{
			if (st[cur<<1] != -inf)
			{
				st[cur<<1] = max(st[cur<<1], lz[cur]);
				lz[cur<<1] = max(lz[cur<<1], lz[cur]);
			}
			if (st[cur<<1|1] != -inf)
			{
				st[cur<<1|1] = max(st[cur<<1|1], lz[cur]);
				lz[cur<<1|1] = max(lz[cur<<1|1], lz[cur]);
			}
			lz[cur] = 0;
		}
	}
	ll query(int cur, int b, int e, int l, int h)
	{
		if (l <= b && e <= h)
			return st[cur];
		int m = (b+e)>>1;
		push(cur, b, e, m);
		ll ret = -inf;
		if (l < m)
			ret = query(cur<<1, b, m, l, h);
		if (m < h)
			ret = max(ret, query(cur<<1|1, m, e, l, h));
		return ret;
	}
	void update(int cur, int b, int e, int l, int h, ll x)
	{
		if (l <= b && e <= h)
		{
			if (st[cur] != -inf)
			{
				st[cur] = max(st[cur], x);
				lz[cur] = max(lz[cur], x);
			}
			return;
		}
		int m = (b+e) >> 1;
		push(cur, b, e, m);
		if (l < m)
			update(cur<<1, b, m, l, h, x);
		if (m < h)
			update(cur<<1|1, m, e, l, h, x);
		st[cur] = max(st[cur<<1], st[cur<<1|1]);
	}
	void put(int cur, int b, int e, int p, ll x)
	{
		if (b+1==e)
		{
			st[cur] = x;
			return;
		}
		int m = (b+e)>>1;
		push(cur, b, e, m);
		if (p < m)
			put(cur<<1, b, m, p, x);
		else
			put(cur<<1|1, m, e, p, x);
		st[cur] = max(st[cur<<1], st[cur<<1|1]);
	}
	ll query(int a, int b)
	{
		return query(1, 0, n+1, a, b+1);
	}
	void update(ll x)
	{
		//cout << "update all" << x << "\n";
		update(1, 0, n+1, 0, n+1, x);
	}
	void put(int p, ll x)
	{
		//cout << "put " << p << " " << x << "\n";
		put(1, 0, n+1, p, x);
	}
};

struct monotonic_queue
{
	deque<pair<int, ll>> deq;

	void add(int k, ll v)
	{
		while (!deq.empty() && deq.back().second <= v)
			deq.pop_back();
		deq.push_back({k, v});
	}

	void remove(int k)
	{
		while (!deq.empty() && deq.front().first <= k)
			deq.pop_front();
	}

	ll max()
	{
		return deq.front().second;
	}
};

int main()
{
	//freopen("a.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(0);

	int n, l, r;
	cin >> n >> l >> r;
	vector<int> a(n);
	for (auto &i : a)
		cin >> i;

	vector<ll> dp(n+1, inf);

	set<pair<ll, int>> sat, nsat;

	monotonic_queue mq;
	for (int i = 0; i < l; ++i) mq.add(i, a[i]);

	dp[0] = 0;
	seg_tree st(n+1);
	st.put(0, mq.max());
	nsat.insert({ inf, 0 });

	for (int i = l; i <= n; ++i)
	{
		int from = max(i-r, 0);
		int to = i-l;

		//cout << from << " " << to << " " << i << "\n";
		/*cout << "sat\n";
		for (auto i : sat) cout << i.F << " " << i.S << "\n";
		cout << endl;
		cout << "nsat\n";
		for (auto i : nsat) cout << i.F << " " << i.S << "\n";
		cout << endl;*/

		ll best = st.query(from, to+1);
		//cout << "best" << " " << best << "\n";
		while (!sat.empty() && sat.rbegin()->S < from)
			sat.erase(*sat.rbegin());
		if (!sat.empty()) best = max(best, sat.rbegin()->F);

		dp[i] = best;

		if (i == n) break;
		//to+1
		while (!nsat.empty() && nsat.begin()->F <= a[i])
		{
			sat.insert(*nsat.begin());
			st.put(nsat.begin()->S, -inf);
			nsat.erase(nsat.begin());
		}
		st.update(a[i]);
		mq.add(i, a[i]);
		mq.remove(to);
		pair<ll, int> w = { dp[to+1], mq.max() };
		if (w.F == inf) continue;
		if (w.S >= w.F)
			sat.insert({ w.F, to+1 });
		else
		{
			nsat.insert({ w.F, to+1 });
			st.put(to+1, w.S);
		}
	}

	/*for (int i = 1; i <= n; ++i)
		cout << dp[i] << "\n";*/

	cout << dp[n] << "\n";

	return 0;
}
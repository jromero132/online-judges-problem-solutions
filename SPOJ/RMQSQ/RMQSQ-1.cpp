// Problem name: Range Minimum Query
// Problem link: https://www.spoj.com/problems/RMQSQ/
// Submission link: https://www.spoj.com/submit/RMQSQ/id=22663212

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

template<typename T>
struct rmq // 0-index
{
	int n, lg;
	vector<vector<T>> dp;

	rmq(vector<T> &a) : n(a.size()), lg(__lg(n)), dp(n + 1, vector<T>(lg + 1, numeric_limits<T>::max()))
	{
		for (int j = 1; j <= n; j++)
			dp[j][0] = a[j - 1];

		for (int i = 1; i <= lg; i++)
			for (int j = 1; j <= n - (1 << i) + 1; j++)
				dp[j][i] = min(dp[j][i - 1], dp[j + (1 << (i - 1))][i - 1]);
	}

	T query(int a, int b)
	{
		int l = __lg(++b - ++a + 1);
		return min(dp[a][l], dp[b - (1 << l) + 1][l]);
	}
};

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);

#ifdef JoseA132
	freopen("01.in", "r", stdin);
#endif

	int n, q;
	cin >> n;
	vector<int> v(n);
	for(auto &x : v)
		cin >> x;
	rmq<int> r(v);
	for(cin >> q ; q-- ; ){
		int a, b;
		cin >> a >> b;
		cout << r.query(a, b) << endl;
	}
	return 0;
}
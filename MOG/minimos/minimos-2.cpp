// Problem name: H - Mínimos
// Problem link: https://matcomgrader.com/problem/4705/minimos/
// Submission link: https://matcomgrader.com/submission/62261/

#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

const int N = 30000000 + 100;
int v[N], deq[N];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, a, b, c;
	cin >> n >> m >> a >> b >> c >> v[0] >> v[1];

	for(int i = 2; i < n; ++i)
		v[i] = a * v[i - 2] + b * v[i - 1] + c;

	i64 ans = 0;
	int df = 0, db = 0;

	for(int i = 0; i < m; ++i)
	{
		while(df < db && v[deq[db-1]] > v[i]) --db;

		deq[db++] = i;
	}

	ans += v[deq[df]];

	for(int i = m; i < n; ++i)
	{
		while(df < db && deq[df] + m <= i) ++df;

		while(df < db && v[deq[db-1]] > v[i]) --db;

		deq[db++] = i;
		ans += v[deq[df]];
	}

	cout << ans << endl;

	return 0;
}
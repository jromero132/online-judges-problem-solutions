// Problem name: Islands
// Problem link: https://codeforces.com/gym/101291/problem/H
// Submission link: https://codeforces.com/gym/101291/submission/37240402

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

bool mark[55][55];

int d[][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

int main()
{
	//freopen("a.txt", "r", stdin);
	ios_base::sync_with_stdio(false), cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<string> a(n);
	for (auto &i : a)
		cin >> i;

	function<void(int, int)> dfs = [&](int x, int y)
	{
		mark[x][y] = true;
		for (int k = 0; k < 4; ++k)
		{
			int nx = x+d[k][0], ny = y+d[k][1];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && !mark[nx][ny] && a[nx][ny] != 'W')
				dfs(nx, ny);
		}
	};

	int ans = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (a[i][j] == 'L' && !mark[i][j])
				++ans, dfs(i, j);

	cout << ans << "\n";

    return 0;
}
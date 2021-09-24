// Problem name: Sheba's Amoebas
// Problem link: https://codeforces.com/gym/101673/problem/H
// Submission link: https://codeforces.com/gym/101673/submission/37979688

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int d[][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1} };

int main()
{
	//freopen("a.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<string> s(n);
	for (auto &i : s)
		cin >> i;

	int ans = 0;
	vector<vector<bool>> mark(n, vector<bool>(m));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
		{
			if (!mark[i][j] && s[i][j] == '#')
			{
				++ans;
				mark[i][j] = true;
				queue<pair<int, int>> q;
				q.push({ i, j });
				while (!q.empty())
				{
					int x = q.front().first;
					int y = q.front().second;
					q.pop();

					for (int k = 0; k < 8; ++k)
					{
						int ni = x+d[k][0], nj = y+d[k][1];
						if (ni >= 0 && nj >= 0 && ni < n && nj < m && s[ni][nj] == '#' && !mark[ni][nj])
						{
							mark[ni][nj] = true;
							q.push({ ni, nj });
						}
					}
				}
			}
		}

	cout << ans << "\n";

	return 0;
}

// Problem name: E - Pilas
// Problem link: https://matcomgrader.com/problem/4702/pilas/
// Submission link: https://matcomgrader.com/submission/62257/

#include <bits/stdc++.h>

using namespace std;

const int N = 30000 + 100;

int father[N], size[N], cnt[N];

int root(int u)
{
	if(u != father[u])
	{
		root(father[u]);
		cnt[u] += cnt[father[u]];
		father[u] = father[father[u]];
	}

	return father[u];
}

void join(int u, int v)
{
	u = root(u); v = root(v);

	father[u] = v;
	cnt[u] += size[v];
	size[v] += size[u];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for(int i = 1; i < N; ++i)
		size[father[i] = i] = 1;

	int q;

	cin >> q;

	while(q--)
	{
		string op;
		int x, y;

		cin >> op >> x;

		if(op == "C")
		{
			root(x);
			cout << cnt[x] << endl;
		}
		else
		{
			cin >> y;
			join(x,y);
		}
	}
	
	return 0;
}
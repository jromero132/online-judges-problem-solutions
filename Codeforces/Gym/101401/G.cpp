// Problem name: Balloons (B)
// Problem link: https://codeforces.com/gym/101401/problem/G
// Submission link: https://codeforces.com/gym/101401/submission/43704473

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int id[256];

int main()
{
	//freopen("a.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(0);

	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;

	id['B'] = 0;
	id['G'] = 1;
	id['R'] = 2;

	vector<int> ans(3);
	set<pair<int, int>> a;
	int c = 0;
	for (auto i : s)
		a.insert({ ++c, id[i] }), ans[id[i]]++;

	for (int i, j; m--; )
	{
		cin >> i >> j;
		while (true)
		{
			auto it = a.lower_bound({ i, -1 });
			if (it == a.end() || it->F > j) break;
			ans[it->S]--;
			ans[(it->S+1)%3]++;
			a.erase(it);
		}
		cout << ans[2] << " " << ans[1] << " " << ans[0] << "\n";
	}


	return 0;
}
// Problem name: Counting-out Rhyme
// Problem link: https://codeforces.com/contest/792/problem/B
// Submission link: https://codeforces.com/contest/792/submission/44925390

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define F first
#define S second



int main()
{
	//freopen("a.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(0);

	int n, k;
	cin >> n >> k;

	int x, p = 0;
	vector<int> child(n);
	iota(child.begin(), child.end(), 0);

	for (int i = 1; i <= k; ++i)
	{
		cin >> x;
		p = ((ll)p+x) % n;
		cout << child[p]+1 << " ";
		for (int j = p+1; j < n; ++j)
			child[j-1] = child[j];
		--n;
	}

	return 0;
}
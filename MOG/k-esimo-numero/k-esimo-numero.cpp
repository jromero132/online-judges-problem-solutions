// Problem name: A - K-ésimo número
// Problem link: https://matcomgrader.com/problem/164/k-esimo-numero/
// Submission link: https://matcomgrader.com/submission/99598/

#include <bits/stdc++.h>
#include <ext/algorithm>
#include <ext/numeric>

using namespace std;
using namespace __gnu_cxx;

#define endl '\n'

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> a(2 * n);
	vector<int> xx(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> xx[i];

		a[i + n] = {xx[i]};
	}

	sort(xx.begin(), xx.end());
	xx.erase(unique(xx.begin(), xx.end()), xx.end());

	for (int i = n - 1; i > 0; --i)
		merge(a[i << 1].begin(), a[i << 1].end(), a[i << 1 | 1].begin(),
				a[i << 1 | 1].end(), back_inserter(a[i]));

	while (m--)
	{
		int i, j, k;
		cin >> i >> j >> k;

		--i;

		int lo = 0, hi = xx.size() - 1;

		while (lo < hi)
		{
			int mid = (lo + hi) / 2, x = xx[mid], sum = 0;

			for (int l = i + n, r = j + n; l < r; l >>= 1, r >>= 1)
			{
				if (l & 1)
					sum += distance(a[l].begin(),
							upper_bound(a[l].begin(), a[l].end(), x)), ++l;
				if (r & 1)
					--r, sum += distance(a[r].begin(),
							upper_bound(a[r].begin(), a[r].end(), x));
			}

			if (sum >= k)
				hi = mid;
			else
				lo = mid + 1;
		}

		cout << xx[lo] << endl;
	}

	return 0;
}
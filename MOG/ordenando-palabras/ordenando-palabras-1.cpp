// Problem name: B - Ordenando palabras
// Problem link: https://matcomgrader.com/problem/4699/ordenando-palabras/
// Submission link: https://matcomgrader.com/submission/63585/

#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

vector<int> tmp;

i64 inversions(vector<int> &v, int l, int r)
{
	if(r - l == 1) return 0;

	int m = (l + r) / 2;

	i64 ans = inversions(v, l, m);
	ans += inversions(v, m, r);

	int a = l, b = m, p = 0;

	for( ; a < m && b < r; )
	{
		if(v[a] <= v[b]) tmp[p++] = v[a++];
		else tmp[p++] = v[b++], ans += m - a;
	}

	for( ; a < m; ++a) tmp[p++] = v[a];
	for( ; b < r; ++b) tmp[p++] = v[b];

	for(int i = l; i < r; ++i)
		v[i] = tmp[i - l];

	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	vector< vector<int> > cnt(26);

	int n;
	string a, b;

	cin >> n >> a >> b;

	tmp.resize(n);

	for(int i = 0; i < n; ++i)
		cnt[b[i] - 'A'].push_back(i);

	vector<int> pos(26), v;

	for(int i = 0; i < n; ++i)
		v.push_back(cnt[a[i] - 'A'][pos[a[i] - 'A']++]);

	cout << inversions(v, 0, n) << endl;
	
	return 0;
}
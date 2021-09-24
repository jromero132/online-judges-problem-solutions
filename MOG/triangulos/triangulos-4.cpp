// Problem name: C - Triángulos
// Problem link: https://matcomgrader.com/problem/4700/triangulos/
// Submission link: https://matcomgrader.com/submission/63586/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	vector<int> v;
	int n;

	while(cin >> n && n > 0)
		v.push_back(n);

	sort(v.begin(), v.end());

	for(size_t i = 0; i + 2 < v.size(); ++i)
		if(v[i] + v[i + 1] > v[i + 2])
		{
			cout << v[i] << " " << v[i + 1] << " " << v[i + 2] << endl;
			return 0;
		}

	cout << "NO" << endl;
	
	return 0;
}
// Problem name: F - Ordenando números
// Problem link: https://matcomgrader.com/problem/4703/ordenando-numeros/
// Submission link: https://matcomgrader.com/submission/62259/

#include <bits/stdc++.h>

using namespace std;

bool cmp(string a, string b)
{
	return a + b > b + a;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n; cin >> n;

	vector<string> s(n);

	for(int i = 0; i < n; ++i)
		cin >> s[i];

	sort(s.begin(), s.end(), cmp);

	for(int i = 0; i < n; ++i)
		cout << s[i] << " \n"[i+1==n];

	return 0;
}
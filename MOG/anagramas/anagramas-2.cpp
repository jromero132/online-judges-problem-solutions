// Problem name: G - Anagramas
// Problem link: https://matcomgrader.com/problem/4704/anagramas/
// Submission link: https://matcomgrader.com/submission/62260/

#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

const int MAXL = 21;

i64 fact[MAXL];

i64 calc(const vector<int> &v, int sum)
{
	i64 ans = fact[sum];

	for(size_t i = 0; i < v.size(); ++i)
		ans /= fact[v[i]];

	return ans;
}

string solve(string s, i64 n)
{
	vector<int> v(26);

	for(size_t i = 0; i < s.length(); ++i)
		v[s[i] - 'A']++;

	string ans;

	for(size_t i = 0; i < s.length(); ++i)
		for(int j = 0; j < 26; ++j)
			if(v[j])
			{
				--v[j];				
				i64 tmp = calc(v,s.length() - i - 1);

				if(tmp >= n)
				{
					ans += char('A' + j);
					break;	
				}

				n -= tmp;
				++v[j];
			}

	assert(s.length() == ans.length());

	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	fact[0] = 1LL;
	for(int i = 1; i < MAXL; ++i)
		fact[i] = fact[i - 1] * i;

	int tests;
	cin >> tests;

	while(tests--)
	{
		string s;
		i64 n;
		
		cin >> s >> n;
		cout << solve(s,n) << endl;
	}
	
	return 0;
}
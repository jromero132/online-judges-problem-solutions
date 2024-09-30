// Problem name: D - Cadenas
// Problem link: https://matcomgrader.com/problem/4701/cadenas/
// Submission link: https://matcomgrader.com/submission/62256/

#include <bits/stdc++.h>

using namespace std;

int lcp(const string &s, int sb, int se, int tb, int te)
{
	int ans = 0;

	for( ; sb < se && tb < te && s[sb] == s[tb]; ++sb, ++tb)
		++ans;

	return ans;
}

int lcs(const string &s, int sb, int se, int tb, int te)
{
	int ans = 0;

	for( ; sb < se && tb < te && s[se] == s[te]; --se, --te)
		++ans;

	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	string s;
	cin >> n >> s;

	if(n % 2 == 0)
	{
		cout << "IMPOSIBLE" << endl;
		return 0;
	}

	int len = n / 2;

	if(lcp(s,0,len,len,n)+lcs(s,-1,len-1,len-1,n-1) >= len)
	{
		if(lcp(s,len+1,n,0,len+1)+lcs(s,len,n-1,-1,len) >= len
				&& lcp(s,0,len,len+1,n) != len)
			cout << "AMBIGUA" << endl;
		else cout << s.substr(0,len);
	}
	else if(lcp(s,len+1,n,0,len+1)+lcs(s,len,n-1,-1,len) >= len)
		cout << s.substr(len+1,len) << endl;
	else cout << "IMPOSIBLE" << endl;

	return 0;
}
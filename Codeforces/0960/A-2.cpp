// Problem name: Check the string
// Problem link: https://codeforces.com/contest/960/problem/A
// Submission link: https://codeforces.com/contest/960/submission/37109608

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;



int main()
{
	//freopen("a.txt", "r", stdin);
    ios_base::sync_with_stdio(0), cin.tie(0);

    string s;
    cin >> s;

    auto c = s;
    sort(c.begin(), c.end());
    if (c != s)
    {
    	cout << "NO";
    	return 0;
    }

    map<char, int> mp;
    for (auto i : s)
    	++mp[i];

    if ((mp['c'] == mp['b'] || mp['c'] == mp['a']) && mp['a'] > 0 && mp['b'] > 0)
    	cout << "YES";
    else
    	cout << "NO";

    return 0;
}
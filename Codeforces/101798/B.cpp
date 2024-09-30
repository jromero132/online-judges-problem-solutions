// Problem name: Two Palindromes
// Problem link: https://codeforces.com/gym/101798/problem/B
// Submission link: https://codeforces.com/gym/101798/submission/43222042

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

typedef long long ll;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0);

#ifdef JoseA132
	freopen("01.in", "r", stdin);
#endif

	string s1, s2;
	cin >> s1 >> s2;
	vector<int> cnt(26, 0);
	int odd = 0;
	for(auto c : s1)
		cnt[ c - 97 ]++;
	for(auto c : s2)
		cnt[ c - 97 ]++;
	for(auto x : cnt)
		odd += (x & 1);
	cout << (odd <= 1 ? "YES" : "NO") << endl;
	return 0;
}
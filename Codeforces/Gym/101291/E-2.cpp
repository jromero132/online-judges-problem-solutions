// Problem name: Contest Score
// Problem link: https://codeforces.com/gym/101291/problem/E
// Submission link: https://codeforces.com/gym/101291/submission/37240243

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;


int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL);

	int n, k;
	cin >> n >> k;
	vector<int> t(n);
	for (auto &i : t)
		cin >> i;

	multiset<int> s;
	for (int i = 0; i < k-1; ++i)
		s.insert(t[i]);

	ll ans = 0, time = 0;
	for (int i = k-1; i < n; ++i)
	{
		s.insert(t[i]);
		time += *s.begin();
		ans += time;
		s.erase(s.begin());
	}

	while (!s.empty())
	{
		time += *s.begin();
		ans += time;
		s.erase(s.begin());
	}

	cout << ans << "\n";

    return 0;
}
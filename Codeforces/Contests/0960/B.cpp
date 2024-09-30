// Problem name: Minimize the error
// Problem link: https://codeforces.com/contest/960/problem/B
// Submission link: https://codeforces.com/contest/960/submission/37109899

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;



int main()
{
	//freopen("a.txt", "r", stdin);
    ios_base::sync_with_stdio(0), cin.tie(0);

    ll n, k1, k2, k;
    cin >> n >> k1 >> k2;
    k = k1+k2;

    vector<ll> a(n), b(n);
    for (auto &i : a)
    	cin >> i;
    for (auto &i : b)
    	cin >> i;

    multiset<ll> s;
    for (int i = 0; i < n; ++i)
    	if (a[i] != b[i])
    		s.insert(abs(a[i]-b[i]));

    while (!s.empty() && k)
    {
    	--k;
    	ll x = *s.rbegin();
    	s.erase(s.find(x));

    	if (x-1 > 0) s.insert(x-1);
    }

    if (k == 0)
    {
        ll ans = 0;
        for (auto i : s)
        	ans += i*i;

        cout << ans << "\n";
        return 0;
    }

	cout << k%2 << "\n";

    return 0;
}
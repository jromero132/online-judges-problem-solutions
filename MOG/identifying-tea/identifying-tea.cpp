// Problem name: I - Identifying tea
// Problem link: https://matcomgrader.com/problem/9298/identifying-tea/
// Submission link: https://matcomgrader.com/submission/121133/

#include <bits/stdc++.h>

#define MAX (int)(5e1 + 1)
#define MOD (ll)(1e9 + 7)
#define mod(x) (((x) % MOD + MOD) % MOD)

using namespace std;

typedef long long ll;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int x, ans = 0, y;
	cin >> x;
	for(int i = 0 ; i < 5 ; i++)
        cin >> y, ans += (x == y);
    cout << ans;
    return 0;
}
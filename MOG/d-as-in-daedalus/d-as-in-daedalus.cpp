// Problem name: D - D as in Daedalus
// Problem link: https://matcomgrader.com/problem/9293/d-as-in-daedalus/
// Submission link: https://matcomgrader.com/submission/121154/

#include <bits/stdc++.h>

#define MAX (int)(1e1)
#define MOD (ll)(1e9 + 7)
#define mod(x) (((x) % MOD + MOD) % MOD)

using namespace std;

typedef long long ll;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	ll ans = 0, total = 0, b, sum, now, v;
    while(m--){
        cin >> b >> now;
        sum = now;
        for(int i = 1 ; i < n ; i++)
            cin >> v, sum += v;
        if(sum <= b)
            total += now;
        sum = b - sum + now;
        ll extra = 1;
        while(extra <= sum && extra < 100000)
            extra *= 10;
        ans += extra / 10;
    }
    cout << ans - total;
    return 0;
}
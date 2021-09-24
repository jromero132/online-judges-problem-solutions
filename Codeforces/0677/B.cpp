// Problem name: Vanya and Food Processor
// Problem link: https://codeforces.com/contest/677/problem/B
// Submission link: https://codeforces.com/contest/677/submission/25082540

#include <bits/stdc++.h>

#define pb(n) push_back(n)

using namespace std;

typedef long long ll;

ll n, h, k, v, sum = 0, ans = 0;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> h >> k;
    for(int i = 0 ; i < n ; i++){
        cin >> v;
        if(sum + v > h)
            ans += sum / k, sum %= k;
        if(sum + v > h)
            ans++, sum = 0;
        sum += v;
    }
    ans += sum / k;
    if(sum % k)
        ans++;
    cout << ans;
    return 0;
}
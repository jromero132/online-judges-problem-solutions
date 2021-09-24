// Problem name: LCM
// Problem link: https://vjudge.net/problem/CodeForces-1068B
// Submission link: https://vjudge.net/solution/31780030

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ll n;
    cin >> n;
    int ans = 0;
    for(ll i = 1 ; i * i <= n ; ++i){
        if(n % i == 0){
            ++ans;
            if(i * i != n)
                ++ans;
        }
    }
    cout << ans;
    return 0;
}
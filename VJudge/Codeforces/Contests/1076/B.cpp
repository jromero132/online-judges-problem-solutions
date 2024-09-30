// Problem name: Divisor Subtraction
// Problem link: https://vjudge.net/problem/CodeForces-1076B
// Submission link: https://vjudge.net/solution/31782666

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(ll n){
    if(n % 2 == 0)
        cout << (n >> 1);
    else{
        for(ll i = 3 ; i * i <= n ; i += 2)
            if(n % i == 0){
                cout << ((n - i) >> 1) + 1;
                return;
            }
        cout << 1;
    }
}

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
    solve(n);
    return 0;
}
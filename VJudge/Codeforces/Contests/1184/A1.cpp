// Problem name: Heidi Learns Hashing (Easy)
// Problem link: https://vjudge.net/problem/CodeForces-1184A1
// Submission link: https://vjudge.net/solution/31780630

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(ll r){
    for(ll x = 1 ; x * x < r ; ++x){
        ll xy2 = r - x * x - x - 1;
        if(xy2 <= 0)
            break;
        if(xy2 % (x << 1) == 0){
            cout << x << ' ' << xy2 / (x << 1) << endl;
            return;
        }
    }
    cout << "NO";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ll r;
    cin >> r;
    solve(r);
    return 0;
}
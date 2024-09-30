// Problem name: Interesting Function
// Problem link: https://codeforces.com/contest/1538/problem/F
// Submission link: https://codeforces.com/contest/1538/submission/121061415

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    for(cin >> t ; t-- ; ){
        int a, b;
        cin >> a >> b;
        ll ans = 0;
        while(a | b)
            ans += b - a, a /= 10, b /= 10;
        cout << ans << endl;
    }
    return 0;
}
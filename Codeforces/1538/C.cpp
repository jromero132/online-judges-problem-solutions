// Problem name: Number of Pairs
// Problem link: https://codeforces.com/contest/1538/problem/C
// Submission link: https://codeforces.com/contest/1538/submission/121046295

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    for(cin >> t ; t-- ; ){
        int n, l, r;
        cin >> n >> l >> r;
        int v[ n ];
        for(int i = 0 ; i < n ; ++i){
            cin >> v[ i ];
        }
        sort(v, v + n);
        ll ans = 0, l1, l2;
        for(int i = 0 ; i < n ; ++i){
            l1 = (lower_bound(v + i + 1, v + n, l - v[ i ]) - v);
            l2 = (upper_bound(v + i + 1, v + n, r - v[ i ]) - v);
            ans += l2 - l1;
        }
        cout << ans << endl;
    }
    return 0;
}
// Problem name: Same Differences
// Problem link: https://codeforces.com/contest/1520/problem/D
// Submission link: https://codeforces.com/contest/1520/submission/121069287

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    for(cin >> t ; t-- ; ){
        int n;
        cin >> n;
        map<int, int> m;
        ll ans = 0;
        for(int i = 1, v ; i <= n ; ++i){
            cin >> v;
            ans += m[ v - i ];
            ++m[ v - i ];
        }
        cout << ans << endl;
    }
    return 0;
}
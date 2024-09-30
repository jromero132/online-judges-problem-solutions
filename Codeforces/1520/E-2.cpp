// Problem name: Arranging The Sheep
// Problem link: https://codeforces.com/contest/1520/problem/E
// Submission link: https://codeforces.com/contest/1520/submission/121145511

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
        int n, k = 0;
        cin >> n;
        string level;
        cin >> level;
        for(char x : level)
            n -= x == '.';
        ll ans = 0;
        ++n;
        for(ll i = 1, k = 0 ; i <= level.length() ; ++i){
            if(level[ i - 1 ] == '*'){
                ans += (1 - 2 * ((++k) <= (n >> 1))) * i;
                // cout << i * ((k << 1) - n) << " " << k * (k + 1) << " " << (n * (n + 1) >> 1) << " " << k * (n - (k << 1)) << endl;
                if(k == (n >> 1))
                    --n, ans += i * ((k << 1LL) - n) + k * (k + 1LL) - (n * (n + 1LL) >> 1LL) + k * (n - (k << 1LL)), ++n;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
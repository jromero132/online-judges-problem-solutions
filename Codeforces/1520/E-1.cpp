// Problem name: Arranging The Sheep
// Problem link: https://codeforces.com/contest/1520/problem/E
// Submission link: https://codeforces.com/contest/1520/submission/121145709

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
        int p, q, c;
        for(p = 0, c = 0, ++n ; c < (n >> 1) ; c += level[ p++ ] == '*');
        for(--n, c = 1, q = -(n - c >> 1) ; c <= level.length() ; ++c)
            if(level[ c - 1 ] == '*')
                ans += abs(p - c + q), ++q;
        cout << ans << endl;
    }
    return 0;
}
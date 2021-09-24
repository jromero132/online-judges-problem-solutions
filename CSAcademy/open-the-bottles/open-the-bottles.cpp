// Problem name: Open the Bottles
// Problem link: https://csacademy.com/contest/archive/task/open-the-bottles/
// Submission link: https://csacademy.com/submission/1407532/

#include <bits/stdc++.h>

#define MAX ((int)3)
#define INF ((int)1000000007)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define endl '\n'

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int ans = 0, now, v;
    for(int i = 0 ; i < MAX ; i++){
        now = INF;
        for(int j = 0 ; j < MAX ; j++)
            cin >> v, now = min(now, v);
        ans += now;
    }
    cout << ans << endl;
    return 0;
}
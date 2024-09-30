// Problem name: LCM Problem
// Problem link: https://vjudge.net/problem/CodeForces-1389A
// Submission link: https://vjudge.net/solution/31795829

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
    int l, r;
    cin >> l >> r;
    if((l << 1) > r)
        cout << "-1 -1" << endl;
    else
        cout << l << ' ' << (l << 1) << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    for(cin >> t ; t-- ; solve());
    return 0;
}
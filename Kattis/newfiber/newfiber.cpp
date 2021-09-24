// Problem name: Wireless is the New Fiber
// Problem link: https://open.kattis.com/problems/newfiber
// Submission link: https://open.kattis.com/submissions/3695417

#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define endl '\n'

using namespace std;

typedef pair<int, int> pii;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<pii> deg(n);
    for(int i = 0 ; i < n ; ++i)
        deg[ i ].S = i;
    while(m--){
        int v, w;
        cin >> v >> w;
        ++deg[ v ].F;
        ++deg[ w ].F;
    }
    sort(deg.begin(), deg.end());
    int ans = 0, p1 = 0, p2 = 1;
    vector<pii> tree;
    while(p2 + 1 < n && deg[ p2 ].F == 1)
        ++p2;
    for( ; p1 < n && deg[ p1 ].F == 1 ; ++p1){
        ++ans;
        tree.pb(pii(deg[ p1 ].S, deg[ p2 ].S));
        if(--deg[ p2 ].F == 1 && p2 + 1 < n)
            ++p2;
    }
    for(p2 = max(p2, p1 + 1) ; p2 < n ; ++p2){
        tree.pb(pii(deg[ p1 ].S, deg[ p2 ].S));
        if(!(--deg[ p1 ].F))
            ++p1, ++ans;
        --deg[ p2 ].F;
    }
    cout << n - ans - !deg.back().F << endl << n << ' ' << tree.size() << endl;
    for(auto x : tree)
        cout << x.F << ' ' << x.S << endl;
    return 0;
}
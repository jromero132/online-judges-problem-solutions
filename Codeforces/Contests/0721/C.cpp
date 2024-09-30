// Problem name: Journey
// Problem link: https://codeforces.com/contest/721/problem/C
// Submission link: https://codeforces.com/contest/721/submission/21053688

#include <bits/stdc++.h>

#define pb(n) push_back(n)
#define MAX (int)(5e3 + 5)
#define INF (int)(1e9 + 5)
#define endl '\n'

using namespace std;

typedef pair<int,int> pii;

int n, m, T, ans, DP[ MAX ][ MAX ], road[ MAX ][ MAX ];
vector<pii> streets[ MAX ];

void read(){
    cin >> n >> m >> T;
    for(int i = 0 ; i < m ; i++){
        int u, v, t;
        cin >> u >> v >> t;
        streets[ u ].pb(pii(v, t));
    }
}

void initialize(){
    for(int i = 0 ; i <= n ; i++)
        for(int j = 0 ; j <= n ; j++)
            DP[ i ][ j ] = INF;
    DP[ 1 ][ 1 ] = 0;
}

void solve(){
    for(int i = 1 ; i < n ; i++)
        for(int j = 1 ; j <= n ; j++){
            if(DP[ i ][ j ] == INF)
                continue;
            for(int k = 0 ; k < streets[ j ].size() ; k++){
                int v = streets[ j ][ k ].first;
                int t = streets[ j ][ k ].second;
                if(DP[ i ][ j ] + t <= T && DP[ i + 1 ][ v ] > DP[ i ][ j ] + t){
                    DP[ i + 1 ][ v ] = DP[ i ][ j ] + t;
                    road[ i + 1 ][ v ] = j;
                }
                if(v == n && DP[ i + 1 ][ v ] <= T)
                    ans = max(ans, i + 1);
            }
        }
    cout << ans << endl;
}

void print(){
    if(ans){
        stack<int> path;
        while(ans){
            path.push(n);
            n = road[ ans-- ][ n ];
        }
        cout << path.top(), path.pop();
        while(path.size())
            cout << " " << path.top(), path.pop();
        cout << endl;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    read();
    initialize();
    solve();
    print();
    //system("pause");
    return 0;
}
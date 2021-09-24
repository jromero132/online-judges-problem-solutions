// Problem name: To Go Or Not To Go?
// Problem link: https://codeforces.com/contest/1520/problem/G
// Submission link: https://codeforces.com/contest/1520/submission/121175329

#include <bits/stdc++.h>

#define INF (ll)1e18
#define MAX (int)2e3

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int NOT_REACHED = -2;
int VALID_MOVES[ 4 ][ 2 ] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };

int n, m;
ll w;
int graph[ MAX ][ MAX ], dist[ 2 ][ MAX ][ MAX ], q[ MAX * MAX ][ 2 ];

void bfs(int s, int i, int j){
    dist[ s ][ i ][ j ] = 1;
    q[ 0 ][ 0 ] = i, q[ 0 ][ 1 ] = j;
    for(int nx, ny, l = 0, r = 1 ; l < r ; ++l){
        i = q[ l ][ 0 ], j = q[ l ][ 1 ];
        for(int k = 0 ; k < 4 ; ++k){
            nx = i + VALID_MOVES[ k ][ 0 ];
            ny = j + VALID_MOVES[ k ][ 1 ];
            if(nx >= 0 && nx <= n && ny >= 0 && ny <= m
            && graph[ nx ][ ny ] != -1 && !dist[ s ][ nx ][ ny ]){
                dist[ s ][ nx ][ ny ] = dist[ s ][ i ][ j ] + 1;
                q[ r ][ 0 ] = nx;
                q[ r++ ][ 1 ] = ny;
            }
        }
    }
}

void get_min_path(){
    ll no_portals = !dist[ 0 ][ n ][ m ] ? INF : w * (dist[ 0 ][ n ][ m ] - 1);
    ll one_portal_source = INF, one_portal_target = INF;
    for(int i = 0 ; i <= n ; ++i){
        for(int j = 0 ; j <= m ; ++j){
            if(graph[ i ][ j ] > 0){
                if(dist[ 0 ][ i ][ j ] > 0)
                    one_portal_source = min(one_portal_source, w * (dist[ 0 ][ i ][ j ] - 1) + graph[ i ][ j ]);
                if(dist[ 1 ][ i ][ j ] > 0)
                    one_portal_target = min(one_portal_target, w * (dist[ 1 ][ i ][ j ] - 1) + graph[ i ][ j ]);
            }
        }
    }
    ll ans = min(no_portals, one_portal_source + one_portal_target);
    cout << (ans == INF ? -1 : ans) << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    cin >> n >> m >> w, --n, --m;
    for(int i = 0 ; i <= n ; ++i)
        for(int j = 0 ; j <= m ; cin >> graph[ i ][ j++ ]);
    bfs(0, 0, 0);
    bfs(1, n, m);
    get_min_path();
    return 0;
}
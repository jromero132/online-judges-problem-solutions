// Problem name: Islands
// Problem link: https://codeforces.com/gym/101291/problem/H
// Submission link: https://codeforces.com/gym/101291/submission/37260193

#include <bits/stdc++.h>

#define MAX ((int)50)
#define MAX_MOVE ((int)4)
#define mp make_pair
#define F first
#define S second
#define endl '\n'

using namespace std;

typedef pair<int, int> pii;

const pii dir[] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };

int n, m;
char board[ MAX ][ MAX ];

bool valid(pii v){
    return v.F >= 0 && v.F < n && v.S >= 0 && v.S < m && board[ v.F ][ v.S ] != 'W' && board[ v.F ][ v.S ];
}

void BFS(pii v){
    queue<pii> path;
    path.push(v);
    board[ v.F ][ v.S ] = 0;
    pii w;
    while(!path.empty()){
        v = path.front();
        path.pop();
        for(int i = 0 ; i < MAX_MOVE ; i++){
            w = mp(v.F + dir[ i ].F, v.S + dir[ i ].S);
            if(valid(w)){
                board[ w.F ][ w.S ] = 0;
                path.push(w);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int ans = 0;
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < m ; j++)
            cin >> board[ i ][ j ];
    for(int i = 0 ; i <  n ; i++)
        for(int j = 0 ; j < m ; j++)
            if(board[ i ][ j ] == 'L')
                BFS(mp(i, j)), ans++;
    cout << ans << endl;
    return 0;
}
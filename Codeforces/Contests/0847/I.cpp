// Problem name: Noise Level
// Problem link: https://codeforces.com/contest/847/problem/I
// Submission link: https://codeforces.com/contest/847/submission/30952641

#include <bits/stdc++.h>

#define MAX (int)(25e1 + 3)
#define MAX_MOVE (int)(4)
#define pb(x) push_back(x)
#define mp(i, j) make_pair(i, j)
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;

const int moveX[] = { -1, 0, 1, 0 }, moveY[] = { 0, 1, 0, -1 };

char board[ MAX ][ MAX ];
bool check[ MAX ][ MAX ];
vector<piii> node;
ll n, m, noise[ MAX ][ MAX ];

void BFS(int i, int j, int q){
    memset(check, 0, sizeof(check));
    queue<piii> path;
    piii now;
    int x, y, last = 0;
    path.push(mp(mp(i, j), 0));
    check[ i ][ j ] = 1;
    noise[ i ][ j ] += q;
    while(!path.empty() && (q >> 1)){
        now = path.front();
        path.pop();
        if(now.S > last)
            q >>= (now.S - last), last = now.S;
        if(!q)
            break;
        for(int k = 0 ; k < MAX_MOVE ; k++){
            x = now.F.F + moveX[ k ];
            y = now.F.S + moveY[ k ];
            if(x < 0 || x >= n || y < 0 || y >= m)
                continue;
            if(!check[ x ][ y ] && board[ x ][ y ] != '*'){
                check[ x ][ y ] = 1;
                path.push(mp(mp(x, y), now.S + 1));
                noise[ x ][ y ] += (q >> 1);
            }
        }
    }
}

void print(ll p){
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++)
            cout << noise[ i ][ j ] << " ";
        cout << endl;
    }
    cout << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie( 0 );
	cout.tie(0);

	ll q, p;
	cin >> n >> m >> q >> p;
    for(int i = 0 ; i < n ; i++){
        cin >> board[ i ];
        for(int j = 0 ; board[ i ][ j ] != '\0' ; j++)
            if(board[ i ][ j ] >= 65 && board[ i ][ j ] <= 90)
                node.pb(mp(mp(i, j), board[ i ][ j ] - 64));
    }
    for(int i = 0 ; i < node.size() ; i++){
        BFS(node[ i ].F.F, node[ i ].F.S, q * node[ i ].S);
        //print(p);
    }
    q = 0;
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < m ; j++)
            if(noise[ i ][ j ] > p)
                q++;
    cout << q << endl;
	return 0;
}
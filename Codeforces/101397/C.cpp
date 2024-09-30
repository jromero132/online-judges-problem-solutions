// Problem name: Folding the Figure
// Problem link: https://codeforces.com/gym/101397/problem/C
// Submission link: https://codeforces.com/gym/101397/submission/32759208

#include <bits/stdc++.h>

#define MAX (int)(1e5 + 7)
#define MOD (int)(1e6 + 3)
#define mod(x) (((x) % MOD + MOD) % MOD)
#define POP_COUNT(x) __builtin_popcount(x)
#define mp(i, j) make_pair(i, j)
#define F first
#define S second
#define INF (int)(1e9)
#define MOVE (int)(1 << 2)
#define pb(x) push_back(x)
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const pii move[ MOVE ] = { mp(-1, 0), mp(0, 1), mp(1, 0), mp(0, -1) };

int n, k;
bool check[ MAX ];
map<pii, int> vertex1;
map<int, pii> vertex2;
vector<int> adj[ MAX ];

void BFS(int start){
    queue<int> path;
    path.push(start);
    check[ start ] = 1;
    k -= n;
    int now, x, y, d, xmin = vertex2[ start ].F;
    cout << 'L' << ' ' << xmin << endl;
    for(int i = 1 ; i <= n ; i++)
        cout << vertex2[ i ].F << ' ' << vertex2[ i ].S << endl;
    while(!path.empty() && k > 0){
        now = path.front();
        //cout << "\t\t\t" << now << endl;
        x = vertex2[ now ].F;
        y = vertex2[ now ].S;
        path.pop();
        d = abs(xmin - x);
        cout << x - 2 * d - 1 << ' ' << y << endl;
        k--;
        for(int i = adj[ now ].size() - 1 ; i >= 0 ; i--)
            if(!check[ adj[ now ][ i ] ]){
                check[ adj[ now ][ i ] ] = 1;
                path.push(adj[ now ][ i ]);
            }
    }
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    int t, x, y, xmin, index;
    for(cin >> t ; t-- ; ){
        cin >> n;
        cin >> k;

        xmin = INF;
        memset(check, 0, sizeof(check));
        vertex1.clear();
        vertex2.clear();

        for(int i = 1 ; i <= n ; i++)
            adj[ i ].clear();

        for(int i = 1 ; i <= n ; i++){
            cin >> x >> y;
            vertex1[ mp(x, y) ] = i;
            vertex2[ i ] = mp(x, y);
            if(x < xmin)
                xmin = x, index = i;
            for(int j = 0 ; j < MOVE ; j++)
                if(vertex1[ mp(x + move[ j ].F, y + move[ j ].S) ])
                    adj[ i ].pb(vertex1[ mp(x + move[ j ].F, y + move[ j ].S) ]), adj[ vertex1[ mp(x + move[ j ].F, y + move[ j ].S) ] ].pb(i);
        }
        BFS(index);
    }
	return 0;
}
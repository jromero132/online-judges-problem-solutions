// Problem name: Connected Components?
// Problem link: https://codeforces.com/contest/920/problem/E
// Submission link: https://codeforces.com/contest/920/submission/34953856

#include <bits/stdc++.h>

#define MAX ((int)200001)
#define MOD ((int)1000000007)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define mod(x, y) (((x) % (y) + (y)) % (y))
#define POPCOUNT(x) __builtin_popcount(x)
#define gcd(a, b) __gcd(a, b)
//#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

int n, m;
vi adj[ MAX ];
bool check[ MAX ];
list<int> still;

int BFS(int u){
    check[ u ] = 1;
    queue<int> path;
    path.push(u);
    int ans = 0, p, len;
    while(!path.empty()){
        u = path.front();
        path.pop();
        p = 0;
        len = adj[ u ].size();
        for(list<int>::iterator i = still.begin() ; i != still.end() ; ){
            while(p < len && adj[ u ][ p ] < *i)
                p++;
            if(p < len && adj[ u ][ p ] == *i){
                i++;
                continue;
            }
            check[ *i ] = 1;
            path.push(*i);
            still.erase(i++);
            ans++;
        }
    }
    return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    cin >> n >> m;
    int u, v;
    vi ans;
    for(int i = 0 ; i < m ; i++)
        cin >> u >> v, adj[ u ].pb(v), adj[ v ].pb(u);
    for(int i = 1 ; i <= n ; i++)
        still.push_back(i), sort(adj[ i ].begin(), adj[ i ].end());
    for(int i = 1 ; i <= n ; i++)
        if(!check[ i ])
            ans.pb(BFS(i));
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl << ans[ 0 ];
    for(int i = 1 ; i < ans.size() ; cout << ' ' << ans[ i++ ]);
	return 0;
}
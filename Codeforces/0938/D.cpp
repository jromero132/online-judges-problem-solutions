// Problem name: Buy a Ticket
// Problem link: https://codeforces.com/contest/938/problem/D
// Submission link: https://codeforces.com/contest/938/submission/35358769

#include <bits/stdc++.h>

#define MAX ((int)200005)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define endl '\n'

using namespace std;

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vii;
typedef vector<pll> vpll;

ll cost[ MAX ];
vpll adj[ MAX ];
bool check[ MAX ];

class cmp{
public:
    bool operator () (pll a, pll b){
        return a.F > b.F;
    }
};

priority_queue<pll, vpll, cmp> order;

void update(int v){
    for(int i = adj[ v ].size(), u ; --i >= 0 ; ){
        u = adj[ v ][ i ].F;
        if(cost[ u ] > cost[ v ] + 2 * adj[ v ][ i ].S)
            cost[ u ] = cost[ v ] + 2 * adj[ v ][ i ].S, order.push(mp(cost[ u ], u));
    }
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	ll a, b, c;
	pll aux;
	cin >> n >> m;
	for(int i = 0 ; i < m ; i++)
        cin >> a >> b >> c, adj[ a ].pb(mp(b, c)), adj[ b ].pb(mp(a, c));

    for(int i = 1 ; i <= n ; i++)
        cin >> cost[ i ], order.push(mp(cost[ i ], i));

    while(!order.empty()){
        aux = order.top();
        if(!check[ aux.S ])
            update(aux.S), check[ aux.S ] = 1;
        order.pop();
    }

    for(int i = 1 ; i <= n ; cout << cost[ i++ ] << ' ');

    return 0;
}
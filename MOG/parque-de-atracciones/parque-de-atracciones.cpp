// Problem name: C - Parque de atracciones
// Problem link: https://matcomgrader.com/problem/9239/parque-de-atracciones/
// Submission link: https://matcomgrader.com/submission/120664/

#include <bits/stdc++.h>

#define MAX (int)(5e1 + 1)
#define MOD (ll)(1e9 + 7)
#define mod(x) (((x) % MOD + MOD) % MOD)

using namespace std;

typedef long long ll;

struct terna{
	ll gcd, x, y;

	terna(ll gcd, ll x, ll y) : gcd(gcd), x(x), y(y){ }
};

terna extGCD(ll a, ll b){
	ll x1 = 0, y1 = 1, x2 = 1, y2 = 0, temp, q;
	while(b){
		temp = b;
		q = a / b;
		b = a % b;
		a = temp;

		temp = x1;
		x1 = x2 - q * x1;
		x2 = temp;

		temp = y1;
		y1 = y2 - q * y1;
		y2 = temp;
	}
	return terna(a, x2, y2);
}

ll modInv(ll a){
	return mod(extGCD(a, MOD).x);
}

ll fact(ll n){
	ll ans = 1;
	for(ll i = 2 ; i <= n ; ans = mod(ans * i++));
	return ans;
}

string adj[ MAX ];
ll n, nodes;
bool check[ MAX ];

bool BFS(int s){
	queue<int> path;
	path.push(s);
	check[ s ] = 1;
	int q;
	bool cycle = 1;
	nodes = 0;
	while(!path.empty()){
		nodes++;
		q = 0;
		for(int i = 0 ; i < n ; i++)
			if(adj[ path.front() ][ i ] == 'Y'){
				q++;
				if(!check[ i ])
					path.push(i), check[ i ] = 1;
			}
		cycle &= (q == 2);
		path.pop();
	}
	return cycle;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll ans = 1, q;
	cin >> n;
	for(int i = 0 ; i < n ; i++){
		cin >> adj[ i ];
		q = 0;
		if(adj[ i ][ i ] == 'Y'){
			cout << 0;
			return 0;
		}
		for(int j = 0 ; adj[ i ][ j ] != '\0' ; q += (adj[ i ][ j++ ] == 'Y'));
		if(q > 2){
			cout << 0;
			return 0;
		}
	}
	q = 0;
	for(int i = 0 ; i < n ; i++){
		if(check[ i ])
			continue;
		q++;
		if(BFS(i)){
			cout << 0;
            return 0;
        }
		else
			ans = mod((nodes == 1 ? 1 : 2) * ans);
	}
	cout << mod(fact(q) * ans) << endl;
    return 0;
}
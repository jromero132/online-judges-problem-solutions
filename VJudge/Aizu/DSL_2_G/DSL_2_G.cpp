// Problem name: RSQ and RAQ
// Problem link: https://vjudge.net/problem/Aizu-DSL_2_G
// Submission link: https://vjudge.net/solution/12786005

#include <bits/stdc++.h>

#define MAX ((int)100010)
#define DAD(x) ((x) >> 1)
#define LEFT(x) ((x) << 1)
#define RIGHT(x) ((x) << 1 | 1)
#define endl '\n'

using namespace std;

typedef long long ll;

ll num[ MAX ], tree[ MAX << 2 ], lazy[ MAX << 2 ];

void build(ll node, ll a, ll b){
	if(a > b)
		return;
	if(a == b){
		tree[ node ] = num[ a ];
		return;
	}
	build(LEFT(node), a, DAD(a + b));
	build(RIGHT(node), DAD(a + b) + 1, b);
	tree[ node ] = tree[ LEFT(node) ] + tree[ RIGHT(node) ];
}

ll query(ll node, ll a, ll b, ll i, ll j){
	if(a > b || a > j || b<i)
		return 0;
	if(lazy[ node ]){
		tree[ node ] += lazy[ node ] * (b - a + 1);
		if(a != b){
			lazy[ LEFT(node) ] += lazy[ node ];
			lazy[ RIGHT(node) ] += lazy[ node ];
		}
		lazy[ node ] = 0;
	}
	if(a >= i && b <= j)
		return tree[ node ];
	return query(LEFT(node), a, DAD(a + b), i, j) + query(RIGHT(node), DAD(a+b) + 1, b, i, j);
}

void update(ll node, ll a, ll b, ll i, ll j, ll k){
	if(a > b)
		return;
	if(lazy[ node ]){
		tree[ node ] += lazy[ node ] * (b - a + 1);
		if(a != b){
			lazy[ LEFT(node) ] += lazy[ node ];
			lazy[ RIGHT(node) ] += lazy[ node ];
		}
		lazy[ node ] = 0;
	}
	if(a > b || a > j || b < i)
		return;
	if(a >= i && b <= j){
		tree[ node ] += k * (b - a + 1);
		if(a != b){
			lazy[ LEFT(node) ] += k;
			lazy[ RIGHT(node) ] += k;
		}
		return;
	}
	update(LEFT(node), a, DAD(a + b), i, j, k);
	update(RIGHT(node), DAD(a + b) + 1, b, i, j, k);
	tree[ node ] = tree[ LEFT(node) ] + tree[ RIGHT(node) ];
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, q, a, b, c, d;
	cin >> n >> q;
	n--;
	while(q--){
		cin >> a >> b >> c;
		if(!a){
			cin >> d;
			update(1, 0, n, --b, --c, d);
		}
		else
			cout << query(1, 0, n, --b, --c) << endl;
	}
	return 0;
}
// Problem name: E - Contando personas
// Problem link: https://matcomgrader.com/problem/9532/contando-personas/
// Submission link: https://matcomgrader.com/submission/124745/

#include <bits/stdc++.h>

#define MOD (ll)(1e9 + 9)
#define P1 (ll)(1321)
#define P2 (ll)(1223)
#define MAX (int)(1e3 + 3)
#define mod(x) (((x) % MOD + MOD) % MOD)
#define endl '\n'

using namespace std;

typedef long long ll;

ll n, m, Hash[ MAX ][ MAX ], backHash[ MAX ][ MAX ], p1[ MAX ], p2[ MAX ];
string s[ MAX ];

void setHash(){
	Hash[ 0 ][ 0 ] = backHash[ 0 ][ m ] = backHash[ n ][ 0 ] = 0;
	p1[ 0 ] = p2[ 0 ] = 1;
	for(int i = 1 ; i <= n ; i++){
		Hash[ i ][ 0 ] = backHash[ i ][ m ] = 0;
		p1[ i ] = mod(p1[ i - 1 ] * P1);
	}
	for(int i = 1 ; i <= m ; i++){
		Hash[ 0 ][ i ] = backHash[ n ][ i ] = 0;
		p2[ i ] = mod(p2[ i - 1 ] * P2);
	}
	for(int i = 1, ii = n - 1 ; i <= n ; i++, ii--)
		for(int j = 1, jj = m - 1 ; j <= m ; j++, jj--){
			Hash[ i ][ j ] = mod(s[ i - 1 ][ j - 1 ] + mod(mod(mod(Hash[ i ][ j - 1 ] * P2) + mod(Hash[ i - 1 ][ j ] * P1)) - mod(mod(Hash[ i - 1 ][ j - 1 ] * P1) * P2)));
			backHash[ ii ][ jj ] = mod(s[ ii ][ jj ] + mod(mod(mod(backHash[ ii + 1 ][ jj ] * P1) + mod(backHash[ ii ][ jj + 1 ] * P2)) - mod(mod(backHash[ ii + 1 ][ jj + 1 ] * P1) * P2)));
		}
}

int getHash(int i, int j, int h, int w){
	return mod(mod(mod(Hash[ i + h - 1 ][ j + w - 1 ] - mod(Hash[ i + h - 1 ][ j - 1 ] * p2[ w ])) - mod(Hash[ i - 1 ][ j + w - 1 ] * p1[ h ])) + mod(mod(Hash[ i - 1 ][ j - 1 ] * p1[ h ]) * p2[ w ]));
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//freopen("01.in", "r", stdin);

	int h, w, totalHash, ans = 0;
	string s1[ MAX ], s2[ MAX ];
    cin >> n >> m;
    for(int i = 0 ; i < n ; cin >> s1[ i++ ]);
    cin >> h >> w;
    for(int i = 0 ; i < h ; cin >> s[ i++ ]);
    swap((int&)n, h);
    swap((int&)m, w);
	setHash();
	swap((int&)n, h);
	swap((int&)m, w);
	totalHash = Hash[ h ][ w ];
	swap(s, s1);
	setHash();
	n -= h - 1;
	m -= w - 1;
	for(int i = 1 ; i <= n ; i++)
		for(int j = 1 ; j <= m ; j++)
			ans += (getHash(i, j, h, w) == totalHash);
	cout << ans << endl;
	return 0;
}
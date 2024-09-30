// Problem name: Seat Arrangements
// Problem link: https://codeforces.com/contest/919/problem/C
// Submission link: https://codeforces.com/contest/919/submission/34755516

#include <bits/stdc++.h>

#define MAX ((int)2000)
#define INF ((int)1000)
#define MOD ((int)13)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define POPCOUNT __builtin_popcount
#define CLZ __builtin_clz
#define CTZ __builtin_ctz
#define gcd __gcd
#define endl '\n'

#define DAD(x) ((x) >> 1)
#define LEFT(x) ((x) << 1)
#define RIGHT(x) ((x) << 1 | 1)
#define mod(x, y) (((x) % (y) + (y)) % (y))
#define FORR(t) for(cin >> t ; t-- ; )
#define FOR(i, n) for(int i = 0 ; i < n ; i++)
#define FORI(i, n) for(int i = n ; --i >= 0 ; )

using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int DP[ MAX ];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m, k, ans = 0;
	cin >> n >> m >> k;
	string board[ n ];
	for(int i = 0 ; i < n ; i++){
		cin >> board[ i ];
		DP[ 0 ] = (board[ i ][ 0 ] == '.');
		ans += (DP[ 0 ] >= k);
		for(int j = 1 ; j < m ; j++)
			DP[ j ] = (board[ i ][ j ] == '.' ? DP[ j - 1 ] + 1 : 0), ans += (DP[ j ] >= k);
	}
	if(k > 1){
	for(int j = 0 ; j < m ; j++){
		DP[ 0 ] = (board[ 0 ][ j ] == '.');
		ans += (DP[ 0 ] >= k);
		for(int i = 1 ; i < n ; i++)
			DP[ i ] = (board[ i ][ j ] == '.' ? DP[ i - 1 ] + 1 : 0), ans += (DP[ i ] >= k);
	}
	}
	cout << ans;
	return 0;
}
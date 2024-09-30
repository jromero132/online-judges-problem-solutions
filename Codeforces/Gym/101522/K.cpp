// Problem name: Knights
// Problem link: https://codeforces.com/gym/101522/problem/K
// Submission link: https://codeforces.com/gym/101522/submission/44081924

#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;

using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//ordered_set<int>  s;
//cout << s.order_of_key(2) << endl; // the number of elements in the s less than 2
//cout << *s.find_by_order(0) << endl; // print the 0-th smallest number in s(0-based)

#define DB( x ) cout << #x << " = " << x << endl;
#define LEFT(n) (2 * (n))
#define RIGHT(n) (2 * (n) + 1)

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pii;
typedef pair<pii, int> piii;
typedef pair<pii, pii> piiii;
typedef pair<double, double> point;

const ll MAXV = (ll)(2e5 + 10);
const ll MAXE = (ll)(2e6 + 10);
const ll INF = (ll)(1e16 + 10);
const double EPS = (1e-9);

int n, m, K;

bool tab[105][105];
bool aux[105][105];

void init(){
	memset(aux, 0, sizeof(aux));
	for(int i = 0;i < n;i ++)
		for(int j = 0;j < m;j ++)
			aux[i][j] = tab[i][j];
}

int solve(){
	bool change;
	while(1){//cout << "asdasdas\n";
		change = false;
		for(int i = 0;i < n;i ++)
			for(int j = 0;j < m;j ++)
				if(aux[i][j] == true){
					int last = -1;
					for(int k = j + 1;k < m;k ++)
						if(aux[i][k] == true)
							last = k;
					if(last != -1){

						for(int k = j + 1;k < last;k ++){
							if(aux[i][k] == false){
								aux[i][k] = true;
								change = true;
							}
						}
					}
					break;
				}
		for(int i = 0;i < m;i ++)
			for(int j = 0;j < n;j ++)
				if(aux[j][i] == true){
					int last = -1;
					for(int k = j + 1;k < n;k ++)
						if(aux[k][i] == true)
							last = k;
					if(last != -1){

						for(int k = j + 1;k < last;k ++){
							if(aux[k][i] == false){
							aux[k][i] = true;
							change = true;
							}
						}
					}
					break;
				}
		if(!change)
			break;
	}
	int cnt = 0;
	for(int i = 0;i < n;i ++)
		for(int j = 0;j < m;j ++)
			if(aux[i][j] == true)
				cnt ++;
	return cnt == n * m;
}

pii mapeo[4];

int main(){
	cin.sync_with_stdio( 0 );cin.tie( 0 );

	cin >> n >> m >> K;

	mapeo[0]= {0,0};
	mapeo[1] = {0, m-1};
	mapeo[2] = {n - 1, 0};
	mapeo[3] = {n-1, m-1};

	for(int i = 0;i < K;i ++){
		int a, b;
		cin >> a >> b;
		a --, b --;
		tab[a][b] = true;
	}


	int ans = 1000;

	for(int mask = 0;mask < (1 << 4);mask ++){
		init();
		for(int i = 0;i < 4;i ++)
			if(mask & (1 << i)){

				aux[mapeo[i].first][mapeo[i].second] = true;
			}

		if(solve())
			ans = min(ans, __builtin_popcount(mask));


	}

	cout << ans << "\n";

	return 0;
}
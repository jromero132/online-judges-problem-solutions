// Problem name: Rescue Haibara
// Problem link: https://codeforces.com/gym/101778/problem/E
// Submission link: https://codeforces.com/gym/101778/submission/37286693

#include <bits/stdc++.h>

#define MAX ((int)501)
#define MAX_N ((int)7950)
#define MOD ((int)1000000001)
#define INF ((int)(1 << 30))
#define EPS ((double)1e-7)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define mod(x) (((x) % MOD + MOD) % MOD)
#define modS(x) ((x) % MOD)
#define DAD(x) ((x) >> 1)
#define LEFT(x) ((x) << 1)
#define RIGHT(x) ((x) << 1 | 1)
#define gcd(a, b) __gcd(a, b)
#define endl '\n'

using namespace std;

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldouble;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

struct house{
	int index, money, distance;

	house() : house(0, 0, 0){ }

	house(int index, int money, int distance) : index(index), money(money), distance(distance){ }
};

vector<house> adj[ MAX ];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t, n, x, y;
	house ans, aux;
	for(cin >> t ; t-- ; ){
		cin >> n >> x >> y;
		ans.index = -1;
		ans.distance = INF;
		ans.money = 0;
		for(int i = 1 ; i <= n ; i++){
			cin >> aux.distance >> aux.money;
			aux.index = i;
			if(aux.distance <= x && aux.money >= y)
				if(ans.index == -1 || ans.distance > aux.distance || (ans.distance == aux.distance && ans.money < aux.money))
					ans = aux;
		}
		cout << ans.index << endl;
	}
	return 0;
}
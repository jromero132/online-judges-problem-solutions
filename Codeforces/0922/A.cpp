// Problem name: Cloning Toys
// Problem link: https://codeforces.com/contest/922/problem/A
// Submission link: https://codeforces.com/contest/922/submission/35013835

/*#include <bits/stdc++.h>

#define MAX ((int)1000000)
#define MOD ((int)1000000007)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define DAD(x) ((x) >> 1)
#define LEFT(x) ((x) << 1)
#define RIGHT(x) ((x) << 1 | 1)
#define POPCOUNT __builtin_popcount
#define CLZ __builtin_clz
#define CTZ __builtin_ctz
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, a, b, c, ans = 0;
	cin >> n;
	set<pii> sol;
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= i ; j++){
			a = i;
			b = j;
			c = a ^ b;
			if(a > b)
				swap(a, b);
			if(a > c)
				swap(a, c);
			if(b > c)
				swap(b, c);
			if(c < a + b && sol.find(mp(a, b)) == sol.end())
				cout << a << ' ' << b << ' ' << c << endl,sol.insert(mp(a, b)), sol.insert(mp(a, c));
		}
	}
	cout << (sol.size() >> 1) << endl;
	return 0;
}
*/
#include <bits/stdc++.h>

#define MAX ((int)1000000)
#define MOD ((int)1000000007)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define DAD(x) ((x) >> 1)
#define LEFT(x) ((x) << 1)
#define RIGHT(x) ((x) << 1 | 1)
#define POPCOUNT __builtin_popcount
#define CLZ __builtin_clz
#define CTZ __builtin_ctz
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int x, y;
	cin >> x >> y;
	if(y == 0 || x < y - 1)
		cout << "No";
	else{
		if(x == 0 && y == 1)
			cout << "Yes";
		else if(y != 1 && (x - y + 1) % 2 == 0)
			cout << "Yes";
		else
			cout << "No";
	}
	return 0;
}
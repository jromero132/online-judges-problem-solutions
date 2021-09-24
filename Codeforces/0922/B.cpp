// Problem name: Magic Forest
// Problem link: https://codeforces.com/contest/922/problem/B
// Submission link: https://codeforces.com/contest/922/submission/35014474

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

	int n, a, b, c, ans = 0;
	cin >> n;
	set<pii> sol;
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= i ; j++){
			a = i;
			b = j;
			c = a ^ b;
			if(a < b || b < c)
				continue;
			if(a < b + c)
				ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
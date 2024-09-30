// Problem name: Perfect Number
// Problem link: https://codeforces.com/contest/919/problem/B
// Submission link: https://codeforces.com/contest/919/submission/34747335

#include <bits/stdc++.h>

#define MAX ((int)1000001)
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

bool perfect(int n){
	int sum = 0;
	while(n)
		sum += n % 10, n /= 10;
	return sum == 10;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int k;
	cin >> k;
	ll ans = 19;
	for(int i = 0 ; i < k ; i += perfect(ans++));
	cout << --ans;
	return 0;
}
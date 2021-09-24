// Problem name: A - Suma de tríos
// Problem link: https://matcomgrader.com/problem/9536/suma-de-trios/
// Submission link: https://matcomgrader.com/submission/125224/

#include <bits/stdc++.h>

using namespace std;

#define INF ((int)(1 << 30))
#define MOD ((ll)1000000007)
#define pb push_back
#define endl '\n'

typedef long long ll;
typedef pair<ll, int> pli;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);

	int n;
	cin >> n;
	vector<int> num(n);
	for(int i = 0 ; i < n ; cin >> num[ i++ ]);
	if(n < 3){
		cout << 0 << endl;
		return 0;
	}
	ll ans = 0, sum = num[ 0 ] + num[ 1 ], twice = num[ 0 ] * num[ 1 ];
	for(int i = 2 ; i < n ; i++){
		ans = (ans + twice * num[ i ]) % MOD;
		twice = (twice + sum * num[ i ]) % MOD;
		sum = (sum + num[ i ]) % MOD;
	}
	cout << ans << endl;
}
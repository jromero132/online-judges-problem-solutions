// Problem name: Divisors
// Problem link: https://vjudge.net/problem/SPOJ-DIV
// Submission link: https://vjudge.net/solution/16116571

#include <bits/stdc++.h>

#define MAX ((int)1e6 + 1)
#define pb push_back
#define endl '\n'

using namespace std;

typedef pair<int, int> pii;

vector<int> last(MAX, 1), p;
vector<bool> ok(MAX, 0);

void preprocess(){
	for(int i = 2 ; i < MAX ; last[ i ] = 2, i += 2);
	p.pb(2);
	for(int i = 3 ; i < MAX ; i += 2)
		if(last[ i ] == 1){
			last[ i ] = i;
			if(i < 1000){
				p.pb(i);
				for(int j = i * i ; j < MAX ; j += (i << 1))
					last[ j ] = i;
			}
		}
	for(int i = 0 ; i < p.size() ; ++i)
		for(int j = i + 1 ; j < p.size() ; ++j)
			ok[ p[ i ] * p[ j ] ] = 1;
}

vector<pii> factorize(int n){
	if(n == 1)
		return vector<pii>(0);
	vector<int> f;
	for( ; n != 1 ; n /= last[ n ])
		f.pb(last[ n ]);
	sort(f.begin(), f.end());
	vector<pii> ans;
	int now = 1;
	for(int i = 1 ; i < f.size() ; ++i, ++now)
		if(f[ i ] != f[ i - 1 ])
			ans.pb({ f[ i - 1 ], now }), now = 0;
	ans.pb({ f[ f.size() - 1 ], now });
	return ans;
}

bool solve(int n){
	vector<pii> f = factorize(n);
	if(!f.size() || f.size() > 2)
		return 0;
	return f.size() == 1 ? ok[ f[ 0 ].second + 1 ] : ok[ (f[ 0 ].second + 1) * (f[ 1 ].second + 1) ];
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

#ifdef JoseA132
	freopen("01.in", "r", stdin);
#endif

	preprocess();
	for(int i = 1, n = 0 ; i < MAX ; ++i){
		n += solve(i);
		if(n == 9)
			cout << i << endl, n = 0;
	}
	return 0;
}
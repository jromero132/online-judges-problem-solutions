// Problem name: Medium Factorization
// Problem link: https://vjudge.net/problem/SPOJ-FACTCG2
// Submission link: https://vjudge.net/solution/16114053

#include <bits/stdc++.h>

#define MAX ((int)1e7 + 1)
#define endl '\n'

using namespace std;

typedef long long ll;
vector<int> last(MAX, 1);

void preprocess(){
	for(int i = 2 ; i < MAX ; last[ i ] = 2, i += 2);
	for(int i = 3 ; i < MAX ; i += 2)
		if(last[ i ] == 1)
			for(int j = i ; j < MAX ; j += i)
				last[ j ] = i;
}

void factorize(int n){
	if(n == 1){
		cout << n;
		return;
	}
	factorize(n / last[ n ]);
	cout << " x " << last[ n ];
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

#ifdef JoseA132
	freopen("01.in", "r", stdin);
#endif

	preprocess();
	int n;
	while(cin >> n)
		factorize(n), cout << endl;
	return 0;
}
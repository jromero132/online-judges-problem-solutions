// Problem name: C - Xor de pares
// Problem link: https://matcomgrader.com/problem/5734/xor-de-pares/
// Submission link: https://matcomgrader.com/submission/123651/

#include <bits/stdc++.h>

#define MAX_BITS ((int)20)
#define endl '\n'

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cout.precision(6);
	cout.setf(ios::fixed);

	int n, on, off;
	ll ans = 0;
	cin >> n;
	vi bit(MAX_BITS);
	for(int i = 0 ; i < n ; i++){
		cin >> on;
		for(int j = 0 ; j < MAX_BITS ; j++)
            bit[ j ] += ((on & (1 << j)) != 0);
	}
	for(int i = 0 ; i < MAX_BITS ; i++){
		on = bit[ i ];
		off = n - on;
        ans += (ll)on * off * (1LL << i);
	}
	cout << ans << endl;
	return 0;
}
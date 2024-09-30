// Problem name: MaratonIME rides the university bus
// Problem link: https://codeforces.com/gym/101744/problem/E
// Submission link: https://codeforces.com/gym/101744/submission/43083190

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);

	int n, m, x, y;
	cin >> n >> m;
	vector<ll> sum(n + 1, 0);
	for(int i = 1 ; i <= n ; i++)
		cin >> x, sum[ i ] = sum[ i - 1 ] + x;
	while(m--)
		cin >> x >> y, cout << ((sum[ y ] - sum[ --x ]) & 1 ? "Nao" : "Sim") << endl;
	return 0;
}
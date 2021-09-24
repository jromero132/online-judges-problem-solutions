// Problem name: Delayed Work
// Problem link: https://codeforces.com/gym/101652/problem/Y
// Submission link: https://codeforces.com/gym/101652/submission/43703458

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);

#ifdef JoseA132
	freopen("01.in", "r", stdin);
#endif

	double k, e, x, aux;
	cin >> k >> e >> x, aux = k * e / x;
	int p = (int)sqrt(aux);
	if((double)p * p < aux)
		++p;
	cout << setprecision(3) << fixed << p * x + (k / p) * e << endl;
	return 0;
}
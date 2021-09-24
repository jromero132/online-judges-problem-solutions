// Problem name: MaratonIME challenges USPGameDev
// Problem link: https://codeforces.com/gym/101375/problem/B
// Submission link: https://codeforces.com/gym/101375/submission/37112944

#include <bits/stdc++.h>

#define sqr(x) ((x) * (x))
#define endl '\n'

using namespace std;

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    ll x1, y1, x2, y2, d1, d2;
    cin >> x1 >> y1 >> x2 >> y2;
    d1 = sqr(x1) + sqr(y1);
    d2 = sqr(x2) + sqr(y2);
    cout << (d1 == d2 ? "Empate" : (d1 < d2 ? "Russo" : "Wil")) << endl;
	return 0;
}
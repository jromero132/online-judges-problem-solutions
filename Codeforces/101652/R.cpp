// Problem name: Straight Shot
// Problem link: https://codeforces.com/gym/101652/problem/R
// Submission link: https://codeforces.com/gym/101652/submission/43703770

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);

#ifdef JoseA132
	freopen("01.in", "r", stdin);
#endif

	int n;
	double x, v, avg_y = 0, vel_x;
	cin >> n >> x >> v;
	for(double li, ri, vi ; n-- ; cin >> li >> ri >> vi, avg_y += (ri - li) * vi / x);
	if(fabs(avg_y) >= v)
		cout << "Too hard" << endl;
	else{
		vel_x = sqrt(v * v - avg_y * avg_y);
		if(2 * vel_x < v)
			cout << "Too hard" << endl;
		else
			cout << setprecision(3) << fixed << x / vel_x << endl;
	}
	return 0;
}
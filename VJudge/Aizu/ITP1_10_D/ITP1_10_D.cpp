// Problem name: Distance II
// Problem link: https://vjudge.net/problem/Aizu-ITP1_10_D
// Submission link: https://vjudge.net/solution/12786197

#include <bits/stdc++.h>

#define MAX ((int)110)
#define sqr(x) ((x) * (x))
#define cbr(x) (sqr(x) * (x))
#define endl '\n'

using namespace std;

int x[ MAX ];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	double d1 = 0, d2 = 0, d3 = 0, d4 = 0, v;
	cin >> n;
	for(int i = 0 ; i < n ; cin >> x[ i++ ]);
	for(int i = 0 ; i < n ; i++){
		cin >> v;
		v = abs(v - x[ i ]);
		d1 += v;
		d2 += sqr(v);
		d3 += cbr(v);
		d4 = max(d4, v);
	}
	cout.precision(8);
	cout.flags(ios::fixed);
	cout << d1 << endl << sqrt(d2) << endl << cbrt(d3) << endl << d4 << endl;
	return 0;
}
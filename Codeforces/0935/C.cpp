// Problem name: Fifa and Fafa
// Problem link: https://codeforces.com/contest/935/problem/C
// Submission link: https://codeforces.com/contest/935/submission/35505507

#include <bits/stdc++.h>

#define sqr(x) ((x) * (x))
#define endl '\n'

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	double r, x1, y1, x2, y2;
	cin >> r >> x1 >> y1 >> x2 >> y2;
	cout.precision(10);
	cout.flags(ios::fixed);
	if(sqr(x1 - x2) + sqr(y1 - y2) >= sqr(r))
		cout << x1 << ' ' << y1 << ' ' << r << endl;
	else{
		if(x1 == x2 && y1 == y2)
			cout << x1 - r / 2 << ' ' << y1 << ' ' << r / 2 << endl;
		else if(x1 == x2){
			y1 = (y2 > y1 ? y1 - r : y1 + r);
			cout << x1 << ' ' << (y1 + y2) / 2 << ' ' << abs(y1 - y2) / 2 << endl;
		}
		else{
			double m = (y1 - y2) / (x1 - x2), n = y1 - m * x1, a = sqr(m) + 1, b = -2 * x1 + 2 * m * n - 2 * m * y1, c = sqr(n) + sqr(x1) + sqr(y1) - 2 * n * y1 - sqr(r);
			double xx1 = (-b - sqrt(sqr(b) - 4 * a * c)) / (2 * a), xx2 = (-b + sqrt(sqr(b) - 4 * a * c)) / (2 * a), yy1 = m * xx1 + n, yy2 = m * xx2 + n;
			if(sqr(xx1 - x2) + sqr(yy1 - y2) > sqr(xx2 - x2) + sqr(yy2 - y2))
				cout << (x2 + xx1) / 2 << ' ' << (y2 + yy1) / 2 << ' ' << sqrt(sqr(xx1 - x2) + sqr(yy1 - y2)) / 2 << endl;
			else
				cout << (x2 + xx2) / 2 << ' ' << (y2 + yy2) / 2 << ' ' << sqrt(sqr(xx2 - x2) + sqr(yy2 - y2)) / 2 << endl;
		}
	}
	return 0;
}
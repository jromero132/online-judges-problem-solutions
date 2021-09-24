// Problem name: Crossed Ladders
// Problem link: https://vjudge.net/problem/LightOJ-1062
// Submission link: https://vjudge.net/solution/13249486

#include <bits/stdc++.h>

#define EPS ((double)1e-8)
#define cot(x) (1 / tan(x))
#define endl '\n'

using namespace std;

double getDistance(double x, double y, double c){
    double left = 0, right = max(x, y) - EPS, d, h, alpha, beta;
    while(1){
        d = (left + right) / 2;
        alpha = acos(d / x);
        beta = acos(d / y);
        h = d / (cot(alpha) + cot(beta));
        if(fabs(h - c) < EPS)
            break;
        if(h > c)
            left = d;
        else
            right = d;
    }
    return d;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    cout.precision(8);
    cout.setf(ios::fixed);

    int t;
    double x, y, c;
    cin >> t;
    for(int k = 1 ; k <= t ; k++)
        cin >> x >> y >> c, cout << "Case " << k << ": " << getDistance(x, y, c) << endl;
    return 0;
}
// Problem name: Projections Of A Polygon
// Problem link: https://vjudge.net/problem/SPOJ-KPPOLY
// Submission link: https://vjudge.net/solution/13299136

#include <bits/stdc++.h>

#define MAX ((int)101)
#define INF ((double)1e9)
#define EPS ((double)1e-9)
#define mp make_pair
#define F first
#define S second
#define pi ((double)3.1415926535897932384626433832795)
#define endl '\n'

using namespace std;

typedef pair<double, double> point;

int n;
point p[ MAX ], rot[ MAX ];

double perimeter(double alpha){
    double max_x, max_y, min_x, min_y;
    max_x = max_y = -INF;
    min_x = min_y = INF;
    for(int i = 0 ; i < n ; i++){
        rot[ i ] = mp(p[ i ].F * cos(alpha) - p[ i ].S * sin(alpha), p[ i ].F * sin(alpha) + p[ i ].S * cos(alpha));
        min_x = min(min_x, rot[ i ].F);
        max_x = max(max_x, rot[ i ].F);
        min_y = min(min_y, rot[ i ].S);
        max_y = max(max_y, rot[ i ].S);
    }
    return fabs(max_x - min_x) + fabs(max_y - min_y);
}

double perimeterMinMax(bool minimum){
    double lalpha = 0, ralpha = pi, alpha1, alpha2;
    for(int it = 0 ; it <= 1000 ; it++){
        alpha1 = lalpha + (ralpha - lalpha) / 3;
        alpha2 = ralpha - (ralpha - lalpha) / 3;
        if(perimeter(alpha1) <= perimeter(alpha2)){
            if(minimum)
                ralpha = alpha2;
            else
                lalpha = alpha1;
        }
        else if(minimum)
            lalpha = alpha1;
        else
            ralpha = alpha2;
    }
    return perimeter(alpha1);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    cin >> n;
    for(int i = 0 ; i < n ; i++)
        cin >> p[ i ].F >> p[ i ].S;
    cout.precision(10);
    cout.flags(ios::fixed);
    cout << perimeterMinMax(1) << ' ' << perimeterMinMax(0) << endl;
	return 0;
}
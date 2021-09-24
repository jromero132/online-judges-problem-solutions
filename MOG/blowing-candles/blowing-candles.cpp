// Problem name: K - Blowing Candles
// Problem link: https://matcomgrader.com/problem/9498/blowing-candles/
// Submission link: https://matcomgrader.com/submission/125426/

#include <bits/stdc++.h>

#define oo ((int)1e9)
#define NEXT(i, n) (((i) + 1) % (n))

using namespace std;

typedef complex<double> point;
typedef vector<point> polygon;

inline double cross(point a, point b){ return imag(conj(a) * b); }

inline double area2(point a, point b, point c){ return cross(b - a, c - a); } // Double the area of the triangle ABC.

double area2(const polygon &P){
	double A = 0;
	for(int i = 0, n = P.size() ; i < n ; ++i)
		A += cross(P[ i ], P[ NEXT(i, n) ]);
	return A;
}

double check(int a, int b, int c, int d, const polygon &P){
	for(int i = 0 ; i < 4 && a != c ; ++i){
		if(i == 1)
			swap(a, b);
		else
			swap(c, d);
	}

	if(a == c){ // a admits a support line parallel to bd.
		double A = abs(area2(P[ a ], P[ b ], P[d])); // double of the triangle area.
		double base = abs(P[ b ] - P[ d ]); // base of the triangle abd.
		return A / base;
	}
	return oo;
}

vector<pair<int, int>> antipodal(const polygon &P){
	vector<pair<int, int>> ans;
	int n = P.size();

	if(P.size() == 2)
		ans.push_back({ 0, 1 });

	if(P.size() < 3)
		return ans;

	int q0 = 0;

	while(abs(area2(P[ n - 1 ], P[ 0 ], P[ NEXT(q0, n) ])) > abs(area2(P[ n - 1 ], P[ 0 ], P[ q0 ])))
		++q0;

	for(int q = q0, p = 0 ; q != 0 && p <= q0 ; ++p){
		ans.push_back({ p, q });

		while(abs(area2(P[ p ], P[ NEXT(p, n) ], P[ NEXT(q, n) ])) > abs(area2(P[ p ], P[ NEXT(p, n) ], P[ q ]))){
			q = NEXT(q, n);
			if(p != q0 || q != 0)
				ans.push_back({ p, q });
			else
				return ans;
		}

		if(abs(area2(P[ p ], P[ NEXT(p, n) ], P[ NEXT(q, n) ])) == abs(area2(P[ p ], P[ NEXT(p, n) ], P[ q ]))){
			if(p != q0 || q != n - 1)
				ans.push_back({ p, NEXT(q, n) });
			else
				ans.push_back({ NEXT(p, n), q });
		}
	}
	return ans;
}

double polygon_width(const polygon &P){
	if (P.size() < 3)
		return 0;

	auto pairs = antipodal(P);
	double best = oo;
	int n = pairs.size();

	for(int i = 0 ; i < n ; ++i){
		double tmp = check(pairs[ i ].first, pairs[ i ].second, pairs[ NEXT(i, n) ].first, pairs[ NEXT(i, n) ].second, P);
		best = min(best, tmp);
	}
	return best;
}

bool cmp(point a, point b){
	return a.real() < b.real() || (a.real() == b.real() && a.imag() < b.imag());
}

vector<point> convex_hull(vector<point> v){
	int n = v.size(), k = 0;
	vector<point> ch(2 * n);

	sort(v.begin(), v.end(), cmp);
    for(int i = k = 0 ; i < n ; ch[ k++ ] = v[ i++ ])
        while (k > 1 && area2(ch[ k - 2 ], ch[ k - 1 ], v[ i ]) <= 0) --k;
    for(int i = n - 2, t = k ; i >= 0 ; ch[ k++ ] = v[ i-- ])
        while(k > t && area2(ch[ k - 2 ], ch[ k - 1 ], v[ i ]) <= 0) --k;
    ch.resize(k - (k > 1));
	return ch;
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);

	int n, r;
	double x, y;
	cin >> n >> r;
	polygon p(n);
	for(int i = 0 ; i < n ; i++)
		cin >> x >> y, p[ i ] = { x, y };
	p = convex_hull(p);
	cout << setprecision(13) << polygon_width(p) << endl;
	return 0;
}
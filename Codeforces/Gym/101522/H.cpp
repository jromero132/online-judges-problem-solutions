// Problem name: Hit!
// Problem link: https://codeforces.com/gym/101522/problem/H
// Submission link: https://codeforces.com/gym/101522/submission/44083337

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

struct PT {
	double x, y;
	PT() : x(0), y(0){ }
	PT(double x, double y) : x(x), y(y){ }
	PT(const PT &p) : x(p.x), y(p.y){ }
	PT operator + (const PT &p) const{ return PT(x + p.x, y + p.y); }
	PT operator - (const PT &p) const{ return PT(x - p.x, y - p.y); }
	PT operator * (double c) const{ return PT(x * c, y * c); }
	PT operator / (double c) const{ return PT(x / c, y / c); }
	friend istream &operator >>(istream &in, PT &p){ in >> p.x >> p.y; return in; }
};

double dot(PT p, PT q){ return p.x * q.x + p.y * q.y; }
double dist2(PT p, PT q){ return dot(p - q, p - q); }

PT RotateCCW90(PT p){ return PT(-p.y,p.x); }

vector<PT> CircleCircleIntersection(PT a, PT b, double r, double R) {
	vector<PT> ret;
	double d = sqrt(dist2(a, b));
	if (d > r + R || d + min(r, R) < max(r, R))
		return ret;
	double x = (d * d - R * R + r * r) / (2 * d);
	double y = sqrt(r * r - x * x);
	PT v = (b - a) / d;
	ret.push_back(a + v * x + RotateCCW90(v) * y);
	if (y > 0)
		ret.push_back(a + v * x - RotateCCW90(v) * y);
	return ret;
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);

#ifdef JoseA132
	freopen("01.in", "r", stdin);
#endif

	PT a, b, i;
	double r, R;
	cin >> a >> r >> b >> R;

	i = (dist2(a, b) <= max(r, R) * max(r, R) ? (r <= R ? a : b) : CircleCircleIntersection(a, b, r, R)[ 0 ]);
	cout << setprecision(8) << fixed << i.x << ' ' << i.y << endl;
	return 0;
}
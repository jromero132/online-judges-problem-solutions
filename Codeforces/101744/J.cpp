// Problem name: MaratonIME goes to the japanese restaurant (again)
// Problem link: https://codeforces.com/gym/101744/problem/J
// Submission link: https://codeforces.com/gym/101744/submission/43084846

#include <bits/stdc++.h>

#define EPS ((double)1e-7)
#define sqr(x) ((x) * (x))
#define F first
#define S second
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> point;

struct circle{
	point c;
	int r;
};

inline double dist(point a, point b){
	return sqrt(sqr(a.F - b.F) + sqr(a.S - b.S));
}

bool intersect(circle c1, circle c2){
	return dist(c1.c, c2.c) <= c1.r + c2.r + EPS;
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);

	int n;
	cin >> n;
	vector<circle> c(n);
	for(int i = 0 ; i < n ; i++){
		cin >> c[ i ].c.F >> c[ i ].c.S >> c[ i ].r;
		for(int j = 0 ; j < i ; j++)
			if(intersect(c[ i ], c[ j ]))
				cout << i + 1 << ' ' << j + 1 << endl;
	}
	return 0;
}
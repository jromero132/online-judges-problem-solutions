// Problem name: A Safe Bet
// Problem link: https://codeforces.com/gym/101205/problem/I
// Submission link: https://codeforces.com/gym/101205/submission/34334191

#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <map>

#define MAX ((int)1000002)
#define SLASH ((bool)0)
#define BACKSLASH ((bool)1)
#define North 0
#define East 1
#define South 2
#define West 3
#define pb(x) push_back(x)
#define mp(i, j) make_pair(i, j)
#define F first
#define S second
#define lowbit(x) ((x) & -(x))
#define endl '\n'

using namespace std;

typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<pii, bool> piib;
typedef pair<int, pii> piii;
typedef map<int, bool> mib;
typedef map<int, int> mii;

map<int, mib> rows, columns;

int r, c, tree[ MAX ];

bool cmp1(piii a, piii b){
	return a.F < b.F;
}

bool cmp2(piib a, piib b){
	return a.F < b.F;
}

int query(int i){
	int sum = 0;
	for( ; i >= 0 ; i -= lowbit(i + 1))
		sum += tree[ i ];
	return sum;
}

int query(int l, int r){
	return query(r) - (l == 0 ? 0 : query(l - 1));
}

void update(int i, int v){
	for( ; i < MAX ; i += lowbit(i + 1))
		tree[ i ] += v;
}

int binarySearch(int l, int r, int value){
	int mid;
	while(l < r){
		mid = (l + r) >> 1;
		if(query(mid) > value)
			r = mid;
		else
			l = mid + 1;
	}
	return l;
}

ull countIntersections(vector<pii> &a, vector<pii> &b, pii &first_intersection) {
	vector<piii> horizontal;
	vector<piib> vertical;

	for(int i = a.size() - 1 ; i > 0 ; i--)
		if(a[ i ].F == a[ i - 1 ].F){
			horizontal.pb(mp(a[ i ].F, mp(min(a[ i ].S, a[ i - 1 ].S), max(a[ i ].S, a[ i - 1 ].S))));
			i--;
		}

	for(int i = b.size() - 1 ; i > 0 ; i--)
		if(b[ i ].S == b[ i - 1 ].S){
			vertical.pb(mp(min(b[ i ], b[ i - 1 ]), 1));
			vertical.pb(mp(max(b[ i ], b[ i - 1 ]), 0));
			i--;
		}

	ull intersections = 0ULL;
	bool first = 1, ok;
	int len1 = horizontal.size(), len2 = vertical.size(), p1 = 0, p2 = 0;
	piii now;
	memset(tree, 0, sizeof(tree));
	sort(horizontal.begin(), horizontal.end(), cmp1);
	sort(vertical.begin(), vertical.end(), cmp2);

	if(len1 == 0 || len2 == 0)
		return 0ULL;

	while(p1 < len1 && horizontal[ p1 ].F < vertical[ p2 ].F.F)
		p1++;
	while(p1 < len1 && p2 < len2){
		while(p2 < len2 && vertical[ p2 ].F.F <= horizontal[ p1 ].F){
			update(vertical[ p2 ].F.S, vertical[ p2 ].S ? 1 : -1);
			p2++;
		}
		if(p2 == len2)
			break;
		ok = 0;
		while(p1 < len1 && horizontal[ p1 ].F < vertical[ p2 ].F.F){
			now = horizontal[ p1++ ];
			if((intersections += query(now.S.F + 1, now.S.S - 1)) > 0ULL && first){
				first_intersection = min(first_intersection, mp(now.F, binarySearch(now.S.F, now.S.S, query(now.S.F))));
				first = 0;
			}
			ok = 1;
		}
		if(!ok)
			p2++;
	}
	return intersections;
}

void getPath(pii p, int dir, vector<pii> &path){
	path.assign(1, p);
	mib *row, *column;
	mib::iterator it;
  	do{
		if(dir & 1){
			row = &rows[ p.F ];
			if(dir == East){
				it = (*row).upper_bound(p.S);
				if(it == (*row).end())
					p.S = c + 1;
				else{
					p.S = (it -> F);
					dir = ((it -> S) == BACKSLASH ? South : North);
				}
			}
			else if(dir == West){
				it = (*row).lower_bound(p.S);
				if(it == (*row).begin())
					p.S = 0;
				else{
					p.S = ((--it) -> F);
					dir = ((it -> S) == BACKSLASH ? North : South);
				}
			}
		}
		else{
			column = &columns[ p.S ];
			if(dir == North){
				it = (*column).lower_bound(p.F);
				if(it == (*column).begin())
					p.F = 0;
				else{
					p.F = ((--it) -> F);
					dir = ((it -> S) == BACKSLASH ? West : East);
				}
			}
			else if(dir == South){
				it = (*column).upper_bound(p.F);
				if(it == (*column).end())
					p.F = r + 1;
				else{
					p.F = (it -> F);
					dir = ((it -> S) == BACKSLASH ? East : West);
				}
			}
		}
		path.pb(p);
	}while(1 <= p.F && p.F <= r && 1 <= p.S && p.S <= c);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int m, n, x, y;
	vector<pii> initial_point_path, final_point_path;
	pii ans;
	ull intersections;

	for(int case_number = 1 ; cin >> r >> c >> m >> n ; case_number++){
		rows.clear();
		columns.clear();

		for (int i = 0; i < m; i++) {
			cin >> x >> y;
			rows[ x ][ y ] = SLASH;
			columns[ y ][ x ] = SLASH;
		}
		for (int i = 0; i < n; i++) {
			cin >> x >> y;
			rows[ x ][ y ] = BACKSLASH;
			columns[ y ][ x ] = BACKSLASH;
		}

		getPath(mp(1, 0), East, initial_point_path);
		getPath(mp(r, c + 1), West, final_point_path);
		ans = mp(r + 1, c + 1);

		cout << "Case " << case_number << ": ";
		if(initial_point_path.back() == mp(r, c + 1)){
			cout << 0 << endl;
			continue;
		}

		intersections = countIntersections(initial_point_path, final_point_path, ans) + countIntersections(final_point_path, initial_point_path, ans);
		if(intersections == 0ULL)
			cout << "impossible";
		else
			cout << intersections << ' ' << ans.first << ' ' << ans.second;
		cout << endl;
	}
	return 0;
}
// Problem name: F - Reparando postes
// Problem link: https://matcomgrader.com/problem/9538/reparando-postes/
// Submission link: https://matcomgrader.com/submission/125422/

#include <bits/stdc++.h>

#define MAX ((int)(1e3 + 1))
#define INF ((int)1e9)
#define endl '\n'

using namespace std;

int pos[ MAX ];

bool f(int n, int m, int p1, int p2, int dist, int first, int second){
	int next = p1 - dist, now = 0;
	for(int i = first - 1 ; i >= 0 && pos[ i ] >= next ; next = pos[ i-- ] - dist, now++);
	next = p2 + dist;
	for(int i = second ; i < n && pos[ i ] <= next ; next = pos[ i++ ] + dist, now++);

	if(now + second - first < m)
		return 0;

	next = p1 + dist, now = 0;
	int p = first - 1;
	for(int i = first ; i < second ; i++){
		while(i < second && pos[ i ] <= next)
			++i;
		if(--i == p)
			return 0;
		if(i == second - 1)
			break;
		next = pos[ p = i ] + dist;
		now++;
	}
	if(next < p2){
		if(pos[ second - 1 ] + dist >= p2)
			now++;
		else
			return 0;
	}
	return now <= m;
}

int binary_search(int left, int right, int n, int m, int p1, int p2, int first, int second){
	int middle;
	while(left < right){
		middle = (left + right) >> 1;
		if(f(n, m, p1, p2, middle, first, second))
			right = middle;
		else
			left = middle + 1;
	}
	return right;
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);

	int t, n, m, p1, p2;
	for(cin >> t ; t-- ; ){
		cin >> n >> m >> p1 >> p2;
		for(int i = 0 ; i < n ; cin >> pos[ i++ ]);
		sort(pos, pos + n);
		m = min(m, n);
		if(p2 < p1)
			swap(p1, p2);
		cout << binary_search(0, 1e6, n, m, p1, p2, lower_bound(pos, pos + n, p1) - pos, lower_bound(pos, pos + n, p2) - pos) << endl;
	}
	return 0;
}
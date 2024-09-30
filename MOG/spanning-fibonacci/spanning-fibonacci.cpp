// Problem name: F - Spanning Fibonacci
// Problem link: https://matcomgrader.com/problem/9111/spanning-fibonacci/
// Submission link: https://matcomgrader.com/submission/123376/

#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define endl '\n'

using namespace std;

typedef pair< int, pair<int, int> > edge;

struct DisjointSets{
	int n;
	vector<int> p, s;

	DisjointSets(int n) : n(n), p(n), s(n, 0){
		for(int i = 0 ; i < n ; i++)
			p[ i ] = i;
	}

	int Find(int v){
		return p[ v ] == v ? v : p[ v ] = Find(p[ v ]);
	}

	bool Merge(int v1, int v2){
		int p1 = Find(v1), p2 = Find(v2);
		if(p1 == p2)
			return 0;
        if(s[ p1 ] > s[ p2 ]){
	        s[ p1 ] += s[ p2 ];
	        p[ p2 ] = p1;
        }
        else{
	        s[ p2 ] += s[ p1 ];
	        p[ p1 ] = p2;
        }
        return 1;
	}
};

int n, m;
vector<edge> edges;

int Kruskal(){
	DisjointSets ds(n);
	int ans = 0;
	for(int i = 0 ; i < m ; i++)
        if(ds.Merge(edges[ i ].S.F - 1, edges[ i ].S.S - 1))
        	ans += edges[ i ].F;
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	int a, b, c;
	for(int i = 0 ; i < m ; i++)
		cin >> a >> b >> c, edges.pb(mp(c, mp(a, b)));
	sort(all(edges));
	int left = max(1, Kruskal());
    for(int i = 0 ; i < m ; i++)
    	edges[ i ].F = !edges[ i ].F;
	reverse(all(edges));
    int right = n - 1 - Kruskal();
    if(left > right){
	    cout << "No" << endl;
	    return 0;
    }
    int last = 1, cur = 1;
    while(cur <= right)
    	swap(last += cur, cur);
	cout << (left <= last ? "Si" : "No") << endl;
	return 0;
}
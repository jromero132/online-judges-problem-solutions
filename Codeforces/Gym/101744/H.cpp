// Problem name: MaratonIME goes to the movies
// Problem link: https://codeforces.com/gym/101744/problem/H
// Submission link: https://codeforces.com/gym/101744/submission/43084002

#include <bits/stdc++.h>

#define pb push_back
#define sqr(x) ((x) * (x))
#define endl '\n'

using namespace std;

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);

	int n, x;
	cin >> n;
	vector<ll> point[ 3 ], sum(2);
	for(int i = 0 ; i < 3 ; i++)
		for(int j = 0 ; j < n ; j++)
			cin >> x, point[ i ].pb(x);
	for(int i = 1 ; i < 3 ; i++)
		for(int j = 0 ; j < n ; j++)
			sum[ i - 1 ] += sqr(point[ 0 ][ j ] - point[ i ][ j ]);
	cout << (sum[ 0 ] <= sum[ 1 ] ? "Yan" : "MaratonIME") << endl;
	return 0;
}
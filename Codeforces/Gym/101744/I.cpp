// Problem name: MaratonIME goes to a japanese restaurant
// Problem link: https://codeforces.com/gym/101744/problem/I
// Submission link: https://codeforces.com/gym/101744/submission/43084625

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);

	int n, t;
	cin >> n >> t;
	vector<int> dish(n), sum(2, 0), cnt(2, 0);
	for(int i = 0 ; i < n ; i++)
		cin >> dish[ i ];
	for(int i = 0 ; i < n && (sum[ 0 ] += dish[ i ]) <= t ; ++i, cnt[ 0 ]++);
	for(int i = n - 1 ; i >= 0 && (sum[ 1 ] += dish[ i ]) <= t ; --i, cnt[ 1 ]++);
	if(cnt[ 0 ] == cnt[ 1 ])
		cout << "Empate" << endl;
	else
		cout << (cnt[ 0 ] > cnt[ 1 ] ? "Yan" : "Nathan") << endl;
	return 0;
}
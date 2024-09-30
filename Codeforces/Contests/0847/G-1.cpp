// Problem name: University Classes
// Problem link: https://codeforces.com/contest/847/problem/G
// Submission link: https://codeforces.com/contest/847/submission/30967196

#include <bits/stdc++.h>

#define MAXC (int)(1e1)
#define MAX (int)(1e3 + 5)

using namespace std;

int room[ MAX ];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie( 0 );
	cout.tie(0);

	int n, ans = 0;
	cin >> n;
	string s;
	for(int i = 0 ; i < n ; i++){
		cin >> s;
		for(int j = 0 ; s[ j ] != '\0' ; ans = max(ans, room[ j ] += s[ j ] - 48), j++);
	}
	cout << ans;
	return 0;
}
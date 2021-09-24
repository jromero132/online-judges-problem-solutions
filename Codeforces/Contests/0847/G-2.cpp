// Problem name: University Classes
// Problem link: https://codeforces.com/contest/847/problem/G
// Submission link: https://codeforces.com/contest/847/submission/30951444

#include <bits/stdc++.h>

#define MAXC (int)(1e1)
#define MAX (int)(1e3 + 5)

using namespace std;

int dp[10];
int n;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie( 0 );
	cout.tie(0);

	cin >> n;
	string s;

	for(int i = 0;i < n;i ++){
		cin >> s;
		for(int j = 0;j < s.size();j ++)
			if(s[j] == '1')dp[j] ++;
	}

	int sol = 0;

	for(int i = 0;i < 7;i ++)
		sol = max(sol, dp[i]);

	cout << sol << "\n";

	return 0;
}
/*
3
5 1	1

 */
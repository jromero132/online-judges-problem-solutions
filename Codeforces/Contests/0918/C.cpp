// Problem name: The Monster
// Problem link: https://codeforces.com/contest/918/problem/C
// Submission link: https://codeforces.com/contest/918/submission/34687468

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	string s;
	cin >> s;
	int ans = 0, inf, sup;
	for(int i = 0 ; s[ i ] != '\0' ; i++){
		inf = sup = 0;
		for(int j = i ; s[ j ] != '\0' ; j++){
			if(s[ j ] == '(')
				inf++, sup++;
			else if(s[ j ] == ')')
				inf--, sup--;
			else
				inf--, sup++;
			if(inf == -1)
				inf = 0;
			if(sup == -1)
				break;
			if(((j - i) & 1) && !inf)
				ans++;
		}
	}
	cout << ans;
	return 0;
}
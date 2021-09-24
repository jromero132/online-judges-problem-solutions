// Problem name: Fafa and his Company
// Problem link: https://codeforces.com/contest/935/problem/A
// Submission link: https://codeforces.com/contest/935/submission/35478647

#include <bits/stdc++.h>

#define MAX ((int)32000)
#define endl '\n'

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, ans = 0;
	cin >> n;
	for(int i = 1 ; i * i <= n ; i++){
		if(!(n % i)){
			ans++;
			if(n / i != i)
				ans++;
		}
	}
	cout << ans - 1 << endl;
	return 0;
}
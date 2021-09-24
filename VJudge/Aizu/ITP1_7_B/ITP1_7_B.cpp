// Problem name: How many ways?
// Problem link: https://vjudge.net/problem/Aizu-ITP1_7_B
// Submission link: https://vjudge.net/solution/12786145

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, x, ans;
	while(cin >> n >> x && n){
		ans = 0;
		for(int i = 1 ; i <= n ; i++){
			for(int j = i + 1, k ; j <= n ; j++){
				k = x - i - j;
				if(k > j && k <= n)
					ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
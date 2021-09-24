// Problem name: Borya's Diagnosis
// Problem link: https://codeforces.com/contest/879/problem/A
// Submission link: https://codeforces.com/contest/879/submission/31774385

#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, ans = 0, s, d, k;
	cin >> n;
	while(n--){
		cin >> s >> d;
		while(s <= ans)
			s += d;
		ans = s;
	}
	cout << ans;
	return 0;
}
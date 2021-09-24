// Problem name: MaratonIME goes karting
// Problem link: https://codeforces.com/gym/101744/problem/L
// Submission link: https://codeforces.com/gym/101744/submission/43083027

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);

	int n, p = 0, t = 0;
	cin >> n;
	vector<int> num(n);
	for(int i = 0 ; i < n ; i++){
		cin >> num[ i ];
		if(num[ i ] > num[ p ])
			p = i, t = 1;
		else if(num[ i ] == num[ p ])
			++t;
	}
	cout << (t == 1 ? ++p : -1) << endl;
	return 0;
}
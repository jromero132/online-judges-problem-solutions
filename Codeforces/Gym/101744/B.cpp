// Problem name: MaratonIME plays Cîrokime
// Problem link: https://codeforces.com/gym/101744/problem/B
// Submission link: https://codeforces.com/gym/101744/submission/43082620

#include <bits/stdc++.h>

#define LOG2(x) (32 - __builtin_clz(x))
#define endl '\n'

using namespace std;

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);

	int n;
	cin >> n;
	cout << LOG2(n) << endl;
	return 0;
}
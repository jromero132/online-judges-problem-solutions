// Problem name: Small, Large, or Equal
// Problem link: https://vjudge.net/problem/Aizu-ITP1_2_A
// Submission link: https://vjudge.net/solution/12786120

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int a, b;
	cin >> a >> b;
	cout << "a " << (a == b ? "==" : (a > b ? ">" : "<")) << " b" << endl;
	return 0;
}
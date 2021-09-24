// Problem name: Rectangle
// Problem link: https://vjudge.net/problem/Aizu-ITP1_1_C
// Submission link: https://vjudge.net/solution/12786122

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int a, b;
	cin >> a >> b;
	cout << a * b << ' ' << ((a + b) << 1) << endl;
	return 0;
}
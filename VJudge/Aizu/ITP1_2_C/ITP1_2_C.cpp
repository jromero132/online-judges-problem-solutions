// Problem name: Sorting Three Numbers
// Problem link: https://vjudge.net/problem/Aizu-ITP1_2_C
// Submission link: https://vjudge.net/solution/12786114

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int a[ 3 ];
	cin >> a[ 0 ] >> a[ 1 ] >> a[ 2 ];
	sort(a, a + 3);
	cout << a[ 0 ] << ' ' << a[ 1 ] << ' ' << a[ 2 ] << endl;
	return 0;
}
// Problem name: BBuBBBlesort!
// Problem link: https://vjudge.net/problem/AtCoder-agc003_c
// Submission link: https://vjudge.net/solution/12796132

#include <bits/stdc++.h>

#define MAX ((int)100010)
#define endl '\n'

using namespace std;

int array1[ MAX ], array2[ MAX ];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, ans = 0;
	cin >> n;
	for(int i = 0 ; i < n ; i++)
		cin >> array1[ i ], array2[ i ] = array1[ i ];
	sort(array2, array2 + n);
	for(int i = 0 ; i < n ; i++)
		ans += abs(lower_bound(array2, array2 + n, array1[ i ]) - array2 - i) & 1;
	cout << (ans + 1) / 2 << endl;
	return 0;
}
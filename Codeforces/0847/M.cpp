// Problem name: Weather Tomorrow
// Problem link: https://codeforces.com/contest/847/problem/M
// Submission link: https://codeforces.com/contest/847/submission/30951353

#include <bits/stdc++.h>

#define MAX (int)(1e2 + 5)

using namespace std;

int array[ MAX ];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie( 0 );
	cout.tie(0);

	int n, d;
    cin >> n;
    for(int i = 0 ; i < n ; cin >> array[ i++ ]);
    d = array[ 1 ] - array[ 0 ];
    for(int i = 2 ; i < n ; i++){
        if(array[ i ] - array[ i - 1 ] != d){
            d = 0;
            break;
        }
    }
    cout << array[ n - 1 ] + d;
	return 0;
}
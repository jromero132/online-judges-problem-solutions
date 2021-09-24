// Problem name: Preparing for Merge Sort
// Problem link: https://codeforces.com/contest/847/problem/B
// Submission link: https://codeforces.com/contest/847/submission/30952166

#include <bits/stdc++.h>

#define MAX (int)(2e5 + 5)
#define pb(x) push_back(x)

using namespace std;

typedef vector<int> vi;

int array[ MAX ], m[ MAX ];
vi ans[ MAX ];

int binarySearch(int left, int right, int x){
    int mid;
    while(left <= right){
        mid = (left + right) >> 1;
        if(m[ mid ] >= x)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return left;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie( 0 );
	cout.tie(0);

	int n, p, l = 0;
	cin >> n;
	for(int i = 0 ; i < n ; cin >> array[ i++ ]);
	m[ 0 ] = array[ 0 ];
	ans[ 0 ].pb(m[ 0 ]);
	for(int i = 1 ; i < n ; i++){
        p = binarySearch(0, l, array[ i ]);
        m[ p ] = array[ i ];
        ans[ p ].pb(array[ i ]);
        l = max(p, l);
	}
	for(int i = 0 ; i <= l ; i++){
        for(int j = 0 ; j < ans[ i ].size() ; j++)
            cout << (j ? " " : "") << ans[ i ][ j ];
        cout << endl;
	}
	return 0;
}
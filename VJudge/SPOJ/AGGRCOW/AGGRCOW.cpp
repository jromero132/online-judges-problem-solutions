// Problem name: Aggressive cows
// Problem link: https://vjudge.net/problem/SPOJ-AGGRCOW
// Submission link: https://vjudge.net/solution/13263127

#include <bits/stdc++.h>

#define MAX ((int)100001)
#define endl '\n'

using namespace std;

int n, c, cow[ MAX ];

bool possible(int d){
    int cows = 1, last = cow[ 0 ];
    for(int i = 1 ; i < n ; i++)
        if(cow[ i ] - last >= d)
            cows++, last = cow[ i ];
    return cows >= c;
}

int minimum_distance(){
    int left = 0, right = cow[ n - 1 ] - cow[ 0 ], middle;
    while(left < right){
        middle = (left + right) >> 1;
        if(possible(middle))
            left = middle + 1;
        else
            right = middle - 1;
    }
    return possible(left) ? left : left - 1;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    int t;
    for(cin >> t ; t-- ; ){
        cin >> n >> c;
        for(int i = 0 ; i < n ; i++)
            cin >> cow[ i ];
        sort(cow, cow + n);
        cout << minimum_distance() << endl;
    }
	return 0;
}
// Problem name: Recursive Queries
// Problem link: https://codeforces.com/contest/932/problem/B
// Submission link: https://codeforces.com/contest/932/submission/35299896

#include <bits/stdc++.h>

#define MAX ((int)1000001)
#define MAX_DIG ((int)10)
#define pb push_back
#define mp make_pair
#define endl '\n'

using namespace std;

typedef long long ll;
typedef vector<int> vi;

ll DP[ MAX ][ MAX_DIG ];

ll g(ll n){
    ll ans = 1;
    do{
        if(n % 10)
            ans *= (n % 10);
    }while(n /= 10);
    return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll q;
	for(int i = 1 ; i < MAX ; i++){
        q = i;
        while(q >= 10)
            q = g(q);
        for(int j = 0 ; j < MAX_DIG ; j++)
            DP[ i ][ j ] = DP[ i - 1 ][ j ];
        DP[ i ][ q ]++;
	}
	int l, r, k;
	for(cin >> q ; q-- ; ){
        cin >> l >> r >> k;
        cout << DP[ r ][ k ] - DP[ l - 1 ][ k ] << endl;
	}
	return 0;
}
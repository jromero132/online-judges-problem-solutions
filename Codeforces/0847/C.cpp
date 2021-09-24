// Problem name: Sum of Nestings
// Problem link: https://codeforces.com/contest/847/problem/C
// Submission link: https://codeforces.com/contest/847/submission/30968076

#include <bits/stdc++.h>

#define MAXC (int)(1e1)
#define MAX (int)(1e3 + 5)

using namespace std;

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie( 0 );
	cout.tie(0);

	ll n, k;
	cin >> n >> k;
	if(k > n * (n - 1) / 2){
        cout << "Impossible";
        return 0;
	}
	ll a = 1;
	for( ; a * (a + 1) / 2 <= k ; a++);
	k -= a * (a - 1) / 2 + 1;
	n -= a + (a > k && k >= 0);
	for(int i = 0 ; i < n ; cout << "()", i++);
	for(int i = 0 ; i < a ; i++){
        cout << '(';
        if(i == k)
            cout << "()";
	}
	for(int i = 0 ; i < a ; cout << ')', i++);
	return 0;
}
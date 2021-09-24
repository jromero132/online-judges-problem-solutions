// Problem name: Less or Equal
// Problem link: https://codeforces.com/contest/977/problem/C
// Submission link: https://codeforces.com/contest/977/submission/37946564

#include <bits/stdc++.h>

#define MAX ((int)101)
#define endl '\n'

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k, m;
    cin >> n >> k;
    vector<int> num(n);
    for(int i = 0 ; i < n ; i++)
    	cin >> num[ i ];
    sort(num.begin(), num.end());
    if(k == 0)
    	m = num[ 0 ] - 1;
    else if(n == k)
    	m = num[ n - 1 ];
    else if(num[ k - 1 ] == num[ k ]){
    	cout << -1 << endl;
    	return 0;
    }
    else
    	m = num[ k - 1 ];
    if(m < 1 || m > 1000000000)
    	cout << -1 << endl;
    else
    	cout << m << endl;
    return 0;
}
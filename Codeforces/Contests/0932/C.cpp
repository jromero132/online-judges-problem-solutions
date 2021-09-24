// Problem name: Permutation Cycle
// Problem link: https://codeforces.com/contest/932/problem/C
// Submission link: https://codeforces.com/contest/932/submission/35317022

#include <bits/stdc++.h>

#define MAX ((int)1000001)
#define MAX_DIG ((int)10)
#define pb push_back
#define mp make_pair
#define endl '\n'

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int ans[ MAX ];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, a, b, x, y;
	cin >> n >> a >> b;
	for(x = n / a ; x >= 0 ; x--){
        y = (n - a * x) / b;
        if(y < 0 || a * x + b * y != n)
            continue;
        for(int k = 0 ; k < x ; k++)
            for(int i = 1 ; i <= a ; )
                cout << a * k + (++i <= a ? i : 1) << ' ';
        for(int k = 0 ; k < y ; k++)
            for(int i = 1 ; i <= b ; )
                cout << a * x + b * k + (++i <= b ? i : 1) << ' ';
        return 0;
	}
	cout << -1;
	return 0;
}
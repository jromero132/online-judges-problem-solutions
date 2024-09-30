// Problem name: MaratonIME in the golden moment
// Problem link: https://codeforces.com/gym/101375/problem/D
// Submission link: https://codeforces.com/gym/101375/submission/37113031

#include <bits/stdc++.h>

#define MAX ((int)100000)
#define endl '\n'

using namespace std;

typedef long long ll;

int h[ MAX ];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    int n;
    ll sum = 0, ans = 0;
    cin >> n;
    for(int i = 0 ; i < n ; i++)
        cin >> h[ i ], sum += h[ i ];
    for(int i = 0 ; i < n ; i++)
        ans += h[ i ] * (sum - h[ i ]);
    cout << (ans >> 1LL) << endl;
	return 0;
}
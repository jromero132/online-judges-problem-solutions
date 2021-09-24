// Problem name: Min Pairing
// Problem link: https://csacademy.com/contest/archive/task/min-pairing/
// Submission link: https://csacademy.com/submission/1407494/

#include <bits/stdc++.h>

#define MAX ((int)1000)
#define MOD ((int)1000000007)
#define INF ((int)1000000000)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define endl '\n'

using namespace std;

int num[ MAX ];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, ans, now = 0;
    cin >> n;
    for(int i = 0 ; i < n ; cin >> num[ i++ ]);
    sort(num, num + n);
    for(int i = 1 ; i < n ; i += 2)
        now += num[ i ] - num[ i - 1 ];
    cout << now << endl;
    return 0;
}
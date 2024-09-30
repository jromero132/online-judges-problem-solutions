// Problem name: Erase Value
// Problem link: https://csacademy.com/contest/archive/task/erase-value/
// Submission link: https://csacademy.com/submission/1407490/

#include <bits/stdc++.h>

#define MAX ((int)1001)
#define MOD ((int)1000000007)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define endl '\n'

using namespace std;

int freq[ MAX ];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, v, sum = 0, now = 0;
    cin >> n;
    for(int i = 0 ; i < n ; i++)
        cin >> v, sum += v, now = max(now, ++freq[ v ] * v);
    cout << sum - now << endl;
    return 0;
}
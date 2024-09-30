// Problem name: Frequent Numbers
// Problem link: https://csacademy.com/contest/archive/task/frequent-numbers/
// Submission link: https://csacademy.com/submission/1407474/

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
    
    int n, k, v;
    cin >> n >> k;
    for(int i = 0 ; i < n ; i++)
        cin >> v, freq[ v ]++;
    v = 0;
    for(int i = 0 ; i < MAX ; i++)
        v += (freq[ i ] >= k);
    cout << v << endl;
    return 0;
}
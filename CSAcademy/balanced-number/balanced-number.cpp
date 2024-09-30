// Problem name: Balanced Number
// Problem link: https://csacademy.com/contest/archive/task/balanced-number/
// Submission link: https://csacademy.com/submission/1407481/

#include <bits/stdc++.h>

#define MAX ((int)10)
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
    
    string s;
    cin >> s;
    for(int i = 0 ; s[ i ] ; i++)
        freq[ s[ i ] - 48 ]++;
    bool balanced = 1;
    for(int i = 1 ; i < MAX ; i++)
        balanced &= (freq[ i ] == freq[ i - 1 ]);
    cout << balanced << endl;
    return 0;
}
// Problem name: Encipherment
// Problem link: https://csacademy.com/contest/archive/task/encipherment/
// Submission link: https://csacademy.com/submission/1407498/

#include <bits/stdc++.h>

#define MAX ((int)1000000)
#define MOD ((int)1000000007)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define endl '\n'

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string s, alphabet;
    cin >> s >> alphabet;
    for(int i = 0 ; s[ i ] ; i++)
        s[ i ] = alphabet[ s[ i ] - 97 ];
    cout << s << endl;
    return 0;
}
// Problem name: Links and Pearls
// Problem link: https://codeforces.com/contest/980/problem/A
// Submission link: https://codeforces.com/contest/980/submission/38026311

#include <bits/stdc++.h>

#define MAX ((int)500)
#define pb push_back
#define endl '\n'

using namespace std;



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    int n = 0, m = 0;
    cin >> s;
    for(int i = 0 ; s[ i ] ; i++)
    	n += s[ i ] == 'o', m += s[ i ] == '-';
    if(n == 0 || m % n == 0)
    	cout << "YES" << endl;
    else
    	cout << "NO" << endl;
    return 0;
}
// Problem name: Travel Distance
// Problem link: https://csacademy.com/contest/archive/task/travel-distance/
// Submission link: https://csacademy.com/submission/1407523/

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
    
    int x = 0, y = 0;
    string s;
    cin >> s;
    for(int i = 0 ; s[ i ] ; i++)
        if(s[ i ] == 'N')
            y++;
        else if(s[ i ] == 'S')
            y--;
        else if(s[ i ] == 'E')
            x++;
        else
            x--;
    cout << abs(x) + abs(y) << endl;
    return 0;
}
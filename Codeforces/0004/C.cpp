// Problem name: Registration System
// Problem link: https://codeforces.com/contest/4/problem/C
// Submission link: https://codeforces.com/contest/4/submission/20966806

#include <iostream>
#include <stdio.h>
#include <map>

#define MAX 35
#define endl '\n'

using namespace std;

map<string, int> users;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    string s;
    char ss[ MAX ];
    for(cin >> n ; n ; n--){
        cin >> s;
        sprintf(ss, "%d", users[ s ]);
        if(ss[ 0 ] != '0')
            cout << s + ss << endl;
        else
            cout << "OK" << endl;
        users[ s ]++;
    }
    return 0;
}
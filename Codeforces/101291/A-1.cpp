// Problem name: Alphabet
// Problem link: https://codeforces.com/gym/101291/problem/A
// Submission link: https://codeforces.com/gym/101291/submission/37259915

#include <bits/stdc++.h>

#define MAX ((int)50)
#define endl '\n'

using namespace std;

int DP[ MAX ];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;
    int lis = 0;
    for(int i = 0 ; s[ i ] ; i++){
        DP[ i ] = max(1, DP[ i ]);
        lis = max(lis, DP[ i ]);
        for(int j = i + 1 ; s[ j ] ; j++)
            if(s[ j ] > s[ i ])
                DP[ j ] = max(DP[ j ], DP[ i ] + 1);
    }
    cout << 26 - lis << endl;
    return 0;
}
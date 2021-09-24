// Problem name: Six Sides
// Problem link: https://codeforces.com/gym/101291/problem/K
// Submission link: https://codeforces.com/gym/101291/submission/37239805

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int d1[ 6 ], d2[ 6 ];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i = 0 ; i < 6 ; i++)
        cin >> d1[ i ];
    for(int i = 0 ; i < 6 ; i++)
        cin >> d2[ i ];
    int win = 0, tie = 0;
    for(int i = 0 ; i < 6 ; i++){
        for(int j = 0 ; j < 6 ; j++){
            if(d1[ i ] > d2[ j ])
                win++;
            else if(d1[ i ] == d2[ j ])
                tie++;
        }
    }
    cout.precision(5);
    cout << fixed << win / (36.0 - tie) << endl;
    return 0;
}
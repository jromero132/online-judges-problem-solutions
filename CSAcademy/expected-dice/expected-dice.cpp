// Problem name: Expected Dice
// Problem link: https://csacademy.com/contest/archive/task/expected-dice/
// Submission link: https://csacademy.com/submission/1407521/

#include <bits/stdc++.h>

#define MAX ((int)301)
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
    
    int dice[ 6 ], v, pos = -1;
    for(int i = 0 ; i < 6 ; cin >> dice[ i++ ]);
    for(int i = 0 ; i < 6 ; i++){
        cin >> v;
        for(int j = 0 ; j < 6 ; j++){
            freq[ dice[ j ] + v ]++;
            if(pos == -1 || freq[ dice[ j ] + v ] > freq[ pos ] || (freq[ dice[ j ] + v ] == freq[ pos ] && dice[ j ] + v < pos))
                pos = dice[ j ] + v;
        }
    }
    cout << pos << endl;
    return 0;
}
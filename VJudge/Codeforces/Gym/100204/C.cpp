// Problem name: Fibonacci Subsequence
// Problem link: https://vjudge.net/problem/Gym-100204C
// Submission link: https://vjudge.net/solution/13138138

#include <bits/stdc++.h>

#define MAX ((int)3001)
#define endl '\n'

using namespace std;

int num[ MAX ];
int DP[ MAX ][ MAX ];
unordered_map<int, int> sub;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("fibsubseq.in", "r", stdin);
    freopen("fibsubseq.out", "w", stdout);
    int n, len, last, first, second;
    unordered_map<int, int>::iterator it;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> num[ i ];
        for(int j = i + 1 ; j < n ; j++)
            DP[ i ][ j ] = 1;
    }
    len = 0;
    first = second = num[ 0 ];
    for(int i = n ; --i >= 0 ; ){
        for(int j = 0 ; j < i ; j++){
            it = sub.find(num[ i ] + num[ j ]);
            if(it != sub.end())
                DP[ j ][ i ] = DP[ i ][ it -> second ] + 1;
            if(DP[ j ][ i ] > len){
                len = DP[ j ][ i ];
                first = num[ j ];
                second = num[ i ];
            }
        }
        sub[ num[ i ] ] = i;
    }
    cout << ++len << endl << first;
    for(int i = 1 ; i < len ; i++){
        cout << ' ' << second;
        last = first;
        first = second;
        second += last;
    }
    cout << endl;
    return 0;
}
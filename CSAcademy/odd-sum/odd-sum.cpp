// Problem name: Odd Sum
// Problem link: https://csacademy.com/contest/archive/task/odd-sum/
// Submission link: https://csacademy.com/submission/1407468/

#include <iostream>

#define MAX ((int)100)
#define endl '\n'

using namespace std;

int array[ MAX ];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, ans = 0;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> array[ i ];
        for(int j = 0 ; j < i ; j++)
            if((array[ i ] + array[ j ]) & 1)
                ans++;
    }
    cout << ans << endl;
    return 0;
}
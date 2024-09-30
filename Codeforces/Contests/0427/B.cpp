// Problem name: Prison Transfer
// Problem link: https://codeforces.com/contest/427/problem/B
// Submission link: https://codeforces.com/contest/427/submission/20929350

#include <iostream>

#define MAX (int)(2e5 + 5)

using namespace std;

int array[ MAX ];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, t, c, a = -1, ans = 0;
    cin >> n >> t >> c;
    for(int i = 0 ; i < n ; i++){
        cin >> array[ i ];
        if(array[ i ] > t){
            a = i;
            continue;
        }
        if(i - a == c)
            a++, ans++;
    }
    cout << ans << endl;
    return 0;
}
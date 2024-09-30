// Problem name: Bit++
// Problem link: https://codeforces.com/contest/282/problem/A
// Submission link: https://codeforces.com/contest/282/submission/20929776

#include <iostream>

#define MAX 5

using namespace std;

char s[ MAX ];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, ans = 0;
    for(cin >> n ; n ; n--){
        cin >> s;
        if(s[ 0 ] == '+' || s[ 2 ] == '+')
            ans++;
        else
            ans--;
    }
    cout << ans << endl;
    return 0;
}
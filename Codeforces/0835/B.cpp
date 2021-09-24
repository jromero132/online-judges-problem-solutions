// Problem name: The number on the board
// Problem link: https://codeforces.com/contest/835/problem/B
// Submission link: https://codeforces.com/contest/835/submission/29140643

#include <iostream>
#include <algorithm>

#define MAX (int)(1e5 + 1)
#define endl '\n'

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll sum = 0, k, p = 0;
    string s;
    cin >> k >> s;
    for(int i = 0 ; s[ i ] != '\0' ; sum += s[ i++ ] - 48);
    sort(s.begin(), s.end());
    while(sum < k)
        sum += 57 - s[ p++ ];
    cout << p << endl;
    return 0;
}
// Problem name: 3-divisible Pairs
// Problem link: https://csacademy.com/contest/archive/task/3-divisible-pairs/
// Submission link: https://csacademy.com/submission/1296640/

#include <iostream>

#define MAX ((int)3)

using namespace std;

long long rest[ MAX ];

int main() {
    int n, v;
    long long ans = 0;
    for(cin >> n ; n-- ; )
        cin >> v, ans += rest[ ((3 - (v % 3)) % 3) ], rest[ v % 3 ]++;
    cout << ans;
    return 0;
}
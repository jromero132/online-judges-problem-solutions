// Problem name: 3-divisible Pairs
// Problem link: https://csacademy.com/contest/archive/task/3-divisible-pairs/
// Submission link: https://csacademy.com/submission/1296646/

#include <iostream>

#define MAX ((int)3)

using namespace std;

long long rest[ MAX ];

int main() {
    int n, v;
    long long ans = 0;
    for(cin >> n ; n-- ; )
        cin >> v, rest[ v % 3 ]++;
    cout << ((rest[ 0 ] * (rest[ 0 ] - 1)) >> 1) + rest[ 1 ] * rest[ 2 ];
    return 0;
}
// Problem name: Best Compression Ever
// Problem link: https://codeforces.com/gym/100494/problem/B
// Submission link: https://codeforces.com/gym/100494/submission/21187253

#include <iostream>

#define MAX 64

using namespace std;

typedef long long ll;

ll pot2[ MAX ];

void preprocess(){
    for(int i = pot2[ 0 ] = 1 ; i < MAX ; pot2[ i ] = 2 * pot2[ i - 1 ], i++);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    preprocess();
    ll n, b;
    cin >> n >> b;
    cout << (pot2[ b + 1 ] > n ? "yes" : "no") << endl;
    return 0;
}
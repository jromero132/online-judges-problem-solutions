// Problem name: Tri Tiling
// Problem link: https://vjudge.net/problem/UVA-10918
// Submission link: https://vjudge.net/solution/13246977

#include <bits/stdc++.h>

#define MAX ((int)16)
#define endl '\n'

using namespace std;

typedef long long ll;

ll f[ MAX ] = { 1 };

void preprocess(){
    ll sum = 0;
    for(int i = 1 ; i < MAX ; i++)
        f[ i ] = 3 * (f[ i - 1 ]) + sum, sum += (f[ i - 1 ] << 1);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    preprocess();
    int n;
    while(cin >> n && ~n)
        cout << ((n & 1) ? 0 : f[ n >> 1 ]) << endl;
    return 0;
}
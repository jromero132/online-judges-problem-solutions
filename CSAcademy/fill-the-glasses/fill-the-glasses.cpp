// Problem name: Fill the Glasses
// Problem link: https://csacademy.com/contest/archive/task/fill-the-glasses/
// Submission link: https://csacademy.com/submission/1407478/

#include <bits/stdc++.h>

#define MAX ((int)100)
#define MOD ((int)1000000007)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define endl '\n'

using namespace std;

int glass[ MAX ];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, k, sum = 0;
    cin >> n >> k;
    for(int i = 0 ; i < n ; cin >> glass[ i++ ]);
    sort(glass, glass + n);
    for(int i = 0 ; i < k ; i++)
        sum += glass[ i ];
    cout << (sum + 99) / 100 << endl;
    return 0;
}
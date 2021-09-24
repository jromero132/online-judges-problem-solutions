// Problem name: Remove Duplicates
// Problem link: https://codeforces.com/contest/978/problem/A
// Submission link: https://codeforces.com/contest/978/submission/38161426

#include <bits/stdc++.h>

#define MAX ((int)51)
#define INF ((int)1000000000)
#define MOD ((ll)1000000007)
#define EPS ((double)1e-8)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define mod(x) ((x) % MOD)
#define modS(x) ((((x) % MOD) + MOD) % MOD)
#define DAD(x) ((x) >> 1)
#define LEFT(x) ((x) << 1)
#define RIGHT(x) ((x) << 1 | 1)
#define popcount __builtin_popcount
#define clz __builtin_clz
#define ctz __builtin_ctz
#define gcd __gcd
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("01.in", "r", stdin);
    //freopen("01.out", "w", stdout);

    int n, p = 0;
    cin >> n;
    int ans[ MAX ];
    for(int i = 0 ; i < n ; i++){
        cin >> ans[ i ];
        p++;
        for(int j = 0 ; j < i ; j++)
            if(ans[ j ] == ans[ i ]){
                ans[ j ] = -1;
                p--;
                break;
            }
    }
    cout << p << endl;
    for(int i = 0 ; i < n ; i++)
        if(ans[ i ] != -1)
            cout << ans[ i ] << ' ';
    cout << endl;
    return 0;
}
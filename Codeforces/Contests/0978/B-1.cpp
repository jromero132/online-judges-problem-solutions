// Problem name: File Name
// Problem link: https://codeforces.com/contest/978/problem/B
// Submission link: https://codeforces.com/contest/978/submission/38861603

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
    string ss = "jose\
                 ariel\
                 romero,\
                 esto\
                 es\
                 una\
                 prueba";
    int n, ans = 0;
    string s;
    cin >> n >> s;
    for(int i = 2 ; i < n ; i++)
        if(s[ i ] == 'x' && s[ i - 1 ] == 'x' && s[ i - 2 ] == 'x')
            ans++;
    cout << ans << endl;
    
    
    
    int asdf=13;
    
    
    return 0;
}
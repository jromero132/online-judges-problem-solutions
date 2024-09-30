// Problem name: Bus Video System
// Problem link: https://codeforces.com/contest/978/problem/E
// Submission link: https://codeforces.com/contest/978/submission/38178463

#include <bits/stdc++.h>

#define MAX ((int)100001)
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

int n;
ll w, num[ MAX ];

/*bool f(ll now){
    for(int i = 0 ; i < n ; i++){
        now += num[ i ];
        if(now > w || now < 0LL)
            return 0;
    }
    return 1;
}

int binarySearch(ll lo, ll hi, bool up){
    ll m;
    while(lo + 1 < hi){
        m = (lo + hi) >> 1LL;
        //cout << m << endl;
        if(f(m)){
            if(up)
                lo = m;
            else
                hi = m;
        }
        else{
            hi = m;
        }
    }
    return up ? lo + (f(lo + 1) ? 1 : 0) : lo + 1 - (f(lo) ? 1 : 0);
}*/

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("01.in", "r", stdin);
    //freopen("01.out", "w", stdout);

    ll v;
    cin >> n >> w;
    ll lo = 0, hi = 0, now = 0;
    for(int i = 0 ; i < n ; i++)
        cin >> v, now += v, lo = min(lo, now), hi = max(hi, now);
    cout << (abs(lo) > w || abs(hi) > hi || abs(hi - lo) > w ? 0 : abs(w - hi - abs(lo)) + 1) << endl;
    return 0;
}
// Problem name: Help Farmer
// Problem link: https://codeforces.com/contest/143/problem/C
// Submission link: https://codeforces.com/contest/143/submission/25734683

#include <bits/stdc++.h>

#define MAX (int)(1e3 + 1)
#define pb(x) push_back((x))
#define pf(x) push_front((x))
#define INF (ll)(1e18)
#define LEFT(i) ((i) << 1)
#define RIGHT(i) ((i) << 1 | 1)
#define FATHER(i) ((i) >> 1)
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll n, mi, ma, len = 0;
vector<ll> divisors;

void getDivisors(){
    int sqrtN = (int)(sqrt(n));
    for(int i = 1 ; i <= sqrtN ; i++)
        if(!(n % i)){
            divisors.pb(i);
            len++;
            if(i != n / i)
                divisors.pb(n / i), len++;
        }
}

void solve(){
    ll aux, a, b, c;
    mi = INF;
    ma = 0;
    for(int i = 0 ; i < len ; i++){
        for(int j = 0 ; j < len ; j++){
            if(divisors[ i ] * divisors[ j ] > n)
                continue;
            a = divisors[ i ];
            b = divisors[ j ];
            c = n / (divisors[ i ] * divisors[ j ]);
            if(a * b * c != n)
                continue;
            aux = (a + 1) * (b + 2) * (c + 2);
            ma = max(ma, aux - n);
            mi = min(mi, aux - n);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    getDivisors();
    solve();
    cout << mi << " " << ma;
    return 0;
}
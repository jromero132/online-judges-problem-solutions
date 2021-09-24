// Problem name: Accidental Victory
// Problem link: https://codeforces.com/contest/1490/problem/E
// Submission link: https://codeforces.com/contest/1490/submission/121429979

#include <bits/stdc++.h>

#define f first
#define s second
#define all(x) (x).begin(), (x).end()
#define print(x) cout << (x)
#define prints(x) cout << (x) << ' '
#define printl(x) cout << (x) << endl
#define F0R(i, end) for(int i = 0 ; i < (end) ; ++i)
#define F0Rd(i, begin) for(__typeof(begin) i = (begin) - 1 ; i >= 0 ; --i)

using namespace std;

template<typename T> void read(T &x){ cin >> x; }

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<bool> vb;
typedef vector<ll> vl;
typedef vector<pii> vii;

void solve(){
    int n;
    read(n);
    vii v(n);
    F0R(i, n){
        read(v[ i ].f);
        v[ i ].s = i;
    }
    sort(all(v));
    vl sum(n + 1, 0);
    F0R(i, n)
        sum[ i + 1 ] = sum[ i ] + v[ i ].f;
    int winners = 1;
    vb winner(n, 0);
    winner[ v[ n - 1 ].s ] = 1;
    F0Rd(i, n - 1){
        winner[ v[ i ].s ] = sum[ i + 1 ] >= v[ i + 1 ].f && winner[ v[ i + 1 ].s ];
        if(!winner[ v[ i ].s ])
            break;
        ++winners;
    }
    printl(winners);
    F0R(i, n)
        if(winner[ i ])
            prints(i + 1);
    print('\n');
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    read(t);
    F0R(i, t)
        solve();
    return 0;
}
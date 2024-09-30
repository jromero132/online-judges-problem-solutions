// Problem name: Corrupted Array
// Problem link: https://codeforces.com/contest/1512/problem/D
// Submission link: https://codeforces.com/contest/1512/submission/121287907

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define print(x) cout << (x)
#define prints(x) cout << (x) << ' '
#define printl(x) cout << (x) << endl
#define F0R(i, end) for(int i = 0 ; i < (end) ; ++i)
#define trav(x, v) for(auto &x : v)

using namespace std;

template<typename T> void read(T &x){ cin >> x; }

typedef long long ll;
typedef vector<ll> vl;

void solve(){
    int n;
    read(n), ++n;
    ll sum = 0;
    vl v(n + 1);
    trav(x, v){
        read(x);
        sum += x;
    }
    sort(all(v));
    int p1 = -1, p2 = -1;
    sum -= v[ n ];
    F0R(i, n + 1){
        if(sum - v[ i - (i == n) ] == v[ n - (i == n) ]){
            p1 = i;
            p2 = n - (i == n);
            break;
        }
    }
    if(p1 != -1){
        F0R(i, n + 1)
            if(i != p1 && i != p2)
                prints(v[ i ]);
        print('\n');
    }
    else{
        printl(-1);
    }
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
// Problem name: Permutation by Sum
// Problem link: https://codeforces.com/contest/1512/problem/E
// Submission link: https://codeforces.com/contest/1512/submission/121290318

#include <bits/stdc++.h>

#define print(x) cout << (x)
#define prints(x) cout << (x) << ' '
#define printl(x) cout << (x) << endl
#define F0R(i, end) for(int i = 0 ; i < (end) ; ++i)
#define FORd(i, begin, end) for(__typeof(begin) i = (begin) - 1 ; i >= (end) ; --i)
#define trav(x, v) for(auto &x : v)

using namespace std;

template<typename T> void read(T &x){ cin >> x; }
template<typename T, typename... Args> void read(T &x, Args&... args){ read(x); read(args...); }

typedef vector<int> vi;

void solve(){
    int n, l, r, s;
    read(n, l, r, s), --l;
    int k = r - l;
    if(s < k * (k + 1) / 2 || s > k * (2 * n - k + 1) / 2){
        printl(-1);
        return;
    }
    vi v(n), a(n);
    int p1 = 0, p2 = l;
    --k;
    FORd(i, n + 1, 1){
        if(s - i >= k * (k + 1) / 2){
            s -= (v[ p2++ ] = i);
            --k;
        }
        else{
            if(p1 == l)
                p1 = r;
            v[ p1++ ] = i;
        }
    }
    trav(x, v)
        prints(x);
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
// Problem name: Co-growing Sequence
// Problem link: https://codeforces.com/contest/1547/problem/D
// Submission link: https://codeforces.com/contest/1547/submission/122018167

#include <bits/stdc++.h>

#define print(x) cout << (x)
#define FOR(i, begin, end) for(__typeof(begin) i = (begin) ; i < (end) ; ++i)
#define F0R(i, end) for(int i = 0 ; i < (end) ; ++i)

using namespace std;

template<typename T> void read(T &x){ cin >> x; }

void solve(){
    int n;
    read(n);
    int last, cur;
    read(last);
    print(0);
    FOR(i, 1, n){
        read(cur);
        print(" ");
        print(last ^ (last & cur));
        last = cur | (last ^ (last & cur));
    }
    print("\n");
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
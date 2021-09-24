// Problem name: Maximize the Remaining String
// Problem link: https://codeforces.com/contest/1506/problem/G
// Submission link: https://codeforces.com/contest/1506/submission/121364189

#include <bits/stdc++.h>

#define pb push_back
#define len(x) (int)(x).length()
#define sz(x) (int)(x).size()
#define print(x) cout << (x)
#define F0R(i, end) for(int i = 0 ; i < (end) ; ++i)
#define F0Rd(i, begin) for(__typeof(begin) i = (begin) - 1 ; i >= 0 ; --i)

using namespace std;

template<typename T> void read(T &x){ cin >> x; }
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<int> vi;

void solve(){
    string s;
    read(s);
    vi rep(26, 0);
    F0R(i, len(s))
        ++rep[ s[ i ] - 'a' ];
    stack<char> st;
    vb used(26, 0);
    int p;
    F0R(i, len(s)){
        if(used[ s[ i ] - 'a' ]){
            --rep[ s[ i ] - 'a' ];
            continue;
        }
        while(!st.empty() && st.top() < s[ i ] && rep[ st.top() - 'a' ] > 1)
            used[ st.top() - 'a' ] = 0, --rep[ st.top() - 'a' ], st.pop();
        st.push(s[ i ]);
        used[ s[ i ] - 'a' ] = 1;
    }
    vc ans;
    for( ; !st.empty() ; st.pop())
        ans.pb(st.top());
    F0Rd(i, sz(ans))
        print(ans[ i ]);
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
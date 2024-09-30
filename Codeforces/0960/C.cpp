// Problem name: Subsequence Counting
// Problem link: https://codeforces.com/contest/960/problem/C
// Submission link: https://codeforces.com/contest/960/submission/37110364

#include <bits/stdc++.h>

#define pb push_back
#define endl '\n'

using namespace std;

typedef long long ll;

ll x, d, n, l;
vector< vector<ll> > group;

void solve(ll p, ll l, ll f){
    group.pb(vector<ll>(0));
    int k = 0;
    while(p)
        k++, p >>= 1LL;
    for(int i = 1 ; i < k ; i++)
        group[ l ].pb(f);
    group[ l ].pb(f + d);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    ll p = 1, f = 1;
    cin >> x >> d;
    while(p <= x)
        p <<= 1LL;
    p >>= 1LL;
    while(x){
        if(p <= x){
            solve(p, l, f);
            f += (d << 1LL);
            x -= p;
            n += group[ l++ ].size();
        }
        p >>= 1;
    }
    cout << n << endl;
    for(int i = 0 ; i < l ; i++)
        for(int j = 0 ; j < group[ i ].size() ; j++)
            cout << group[ i ][ j ] << ' ';
	return 0;
}
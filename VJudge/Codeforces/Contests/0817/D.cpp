// Problem name: Imbalanced Array
// Problem link: https://vjudge.net/problem/CodeForces-817D
// Submission link: https://vjudge.net/solution/16669751

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);

#ifdef JoseA132
	freopen("01.in", "r", stdin);
    freopen("01.out", "w", stdout);
#endif

    int n;
    cin >> n;
    vector<int> v(n);
    vector<ll> w1(n), w2(n);
    stack<int> s1, s2;
    ll ans = 0;
    for(int i = 0 ; i < n ; ++i){
        cin >> v[ i ];
        for( ; !s1.empty() && v[ s1.top() ] >= v[ i ] ; s1.pop());
        for( ; !s2.empty() && v[ s2.top() ] <= v[ i ] ; s2.pop());
        w1[ i ] = i - (s1.empty() ? -1 : s1.top());
        w2[ i ] = i - (s2.empty() ? -1 : s2.top());
        s1.push(i);
        s2.push(i);
    }
    for( ; !s1.empty() ; s1.pop());
    for( ; !s2.empty() ; s2.pop());
    for(int i = n - 1 ; i >= 0 ; --i){
        for( ; !s1.empty() && v[ s1.top() ] > v[ i ] ; s1.pop());
        for( ; !s2.empty() && v[ s2.top() ] < v[ i ] ; s2.pop());
        w1[ i ] *= ((s1.empty() ? n : s1.top()) - i);
        w2[ i ] *= ((s2.empty() ? n : s2.top()) - i);
        s1.push(i);
        s2.push(i);
        ans += v[ i ] * (w2[ i ] - w1[ i ]);
    }
    cout << ans << endl;
	return 0;
}
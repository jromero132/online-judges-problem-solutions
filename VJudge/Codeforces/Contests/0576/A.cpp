// Problem name: Vasya and Petya's Game
// Problem link: https://vjudge.net/problem/CodeForces-576A
// Submission link: https://vjudge.net/solution/31795933

#include <bits/stdc++.h>

using namespace std;

vector<int> get_primes(int n){
    vector<int> p(n + 1, 1), primes = { 2 };
    for(int i = 3 ; i <= n ; i += 2)
        if(p[ i ]){
            primes.push_back(i);
            for(int j = i * i ; j <= n ; j += (i << 1))
                p[ j ] = 0;
        }
    return primes;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    vector<int> primes = get_primes(n), ans;
    for(int i = 0 ; i < primes.size() ; ++i)
        for(int p = primes[ i ] ; p <= n ; p *= primes[ i ])
            ans.push_back(p);
    cout << ans.size();
    for(int i = 0 ; i < ans.size() ; ++i)
        cout << (i == 0 ? "\n" : " ") << ans[ i ];
    return 0;
}
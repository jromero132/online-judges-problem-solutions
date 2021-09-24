// Problem name: Ehab and a Special Coloring Problem
// Problem link: https://vjudge.net/problem/CodeForces-1174C
// Submission link: https://vjudge.net/solution/31781100

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> get_primes(int n){
    vector<int> p(n + 1, 0), primes;
    for(int i = 2 ; i <= n ; ++i){
        if(!p[ i ]){
            primes.push_back(i);
            p[ i ] = primes.size();
        }
        for(int j = 0 ; j < primes.size() && (ll)i * primes[ j ] <= n ; ++j){
            p[ i * primes[ j ] ] = p[ primes[ j ] ];
            if(i % primes[ j ] == 0)
                break;
        }
    }
    return p;
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
    vector<int> ans = get_primes(n);
    for(int i = 2 ; i <= n ; ++i)
        cout << ans[ i ] << " \n"[ i == n ];
    return 0;
}
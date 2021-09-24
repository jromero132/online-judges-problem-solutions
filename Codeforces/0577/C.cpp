// Problem name: Vasya and Petya's Game
// Problem link: https://codeforces.com/contest/577/problem/C
// Submission link: https://codeforces.com/contest/577/submission/123058069

#include <bits/stdc++.h>

using namespace std;

vector<int> get_primes(int n){
    vector<int> p(n + 1, 0), primes;
    for(int i = 2 ; i <= n ; ++i){
        if(!p[ i ])
            primes.push_back(i);
        for(int j = 0 ; j < primes.size() && i * primes[ j ] <= n ; ++j){
            p[ i * primes[ j ] ] += 1;
            if(i % primes[ j ] == 0)
                break;
        }
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
    cout << ans.size() << endl;
    for(int i = 0 ; i < ans.size() ; ++i)
        cout << ans[ i ] << " \n"[ i == ans.size() - 1 ];
    return 0;
}
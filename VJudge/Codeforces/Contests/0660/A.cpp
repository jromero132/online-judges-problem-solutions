// Problem name: Co-prime Array
// Problem link: https://vjudge.net/problem/CodeForces-660A
// Submission link: https://vjudge.net/solution/31780357

#include <bits/stdc++.h>

using namespace std;

vector<int> get_primes(int n){
    vector<int> primes;
    for(int i = 2 ; i <= n ; ++i){
        bool prime = 1;
        for(int j = 2 ; j < i ; ++j)
            prime &= i % j != 0;
        if(prime)
            primes.push_back(i);
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

    vector<int> primes = get_primes(100);

    int n;
    cin >> n;
    vector<int> v(n), ans;
    cin >> v[ 0 ];
    ans.push_back(v[ 0 ]);
    for(int i = 1 ; i < n ; ++i){
        cin >> v[ i ];
        if(__gcd(v[ i - 1 ], v[ i ]) != 1){
            for(int j = 0 ; j < primes.size() ; ++j)
                if(v[ i - 1 ] % primes[ j ] != 0 && v[ i ] % primes[ j ] != 0){
                    ans.push_back(primes[ j ]);
                    break;
                }
        }
        ans.push_back(v[ i ]);
    }
    cout << ans.size() - n << endl;
    for(int i = 0 ; i < ans.size() ; ++i)
        cout << ans[ i ] << " \n"[ i == ans.size() - 1 ];
    return 0;
}
// Problem name: Another Problem About Dividing Numbers
// Problem link: https://codeforces.com/contest/1538/problem/D
// Submission link: https://codeforces.com/contest/1538/submission/121058782

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> get_primes(int n){
    vector<int> p(n + 1, 0), primes;
    for(int i = 2 ; i < n ; ++i){
        if(!p[ i ])
            primes.push_back(i);
        for(int j = 0 ; j < primes.size() && (ll)i * primes[ j ] <= n ; ++j){
            p[ i * primes[ j ] ] += 1;
            if(i % primes[ j ] == 0)
                break;
        }
    }
    return primes;
}

int prime_divisors(vector<int> &primes, int n){
    int ans = 0;
    for(int i = 0, c = 0 ; n != 1 && i < primes.size() ; ++i, ans += c, c = 0)
        while(n % primes[ i ] == 0)
            n /= primes[ i ], ++c;
    return ans + (n > 1);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N = 31623; // 31623^2 > 10^9
    vector<int> primes = get_primes(N);

    int t;
    for(cin >> t ; t-- ; ){
        int a, b, k;
        cin >> a >> b >> k;
        if(a > b)
            swap(a, b);
        int pda = prime_divisors(primes, a), pdb = prime_divisors(primes, b);
        cout << ((b % a == 0 && a != b ? 1 : 2) <= k && k <= pda + pdb ? "YES" : "NO") << endl;
    }
    return 0;
}
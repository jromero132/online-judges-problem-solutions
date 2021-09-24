// Problem name: Goldbach's Conjecture
// Problem link: https://vjudge.net/problem/POJ-2262
// Submission link: https://vjudge.net/solution/31779516

#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const int MAX = 1000000;
vector<int> p(MAX, 1), primes;

void find_primes(){
    p[ 0 ] = p[ 1 ] = 0;
    for(int i = 2 ; i < MAX ; ++i){
        if(p[ i ])
            primes.push_back(i);
        for(int j = 0 ; j < primes.size() && (ll)i * primes[ j ] <= MAX ; ++j){
            p[ i * primes[ j ] ] = 0;
            if(i % primes[ j ] == 0)
                break;
        }
    }
}

void solve(int n){
    for(int i = 0 ; ; ++i){
        if(p[ n - primes[ i ] ]){
            cout << n << " = " << primes[ i ] << " + " << n - primes[ i ] << endl;
            return;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    find_primes();
    for(int n ; cin >> n && n ; solve(n));
    return 0;
}
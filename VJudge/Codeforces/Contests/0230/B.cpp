// Problem name: T-primes
// Problem link: https://vjudge.net/problem/CodeForces-230B
// Submission link: https://vjudge.net/solution/31780803

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAX = 1000000;
vector<int> p(MAX + 1, 1);

void find_primes(){
    p[ 0 ] = p[ 1 ] = 0;
    vector<int> primes;
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

void solve(){
    ll n;
    cin >> n;
    ll n2 = sqrt(n);
    cout << (n2 * n2 == n && p[ n2 ] ? "YES" : "NO") << endl;
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

    int t;
    for(cin >> t ; t-- ; solve());
    return 0;
}
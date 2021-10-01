// Problem name: Twin Primes
// Problem link: https://vjudge.net/problem/UVA-10394
// Submission link: https://vjudge.net/solution/32959080

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<pair<int, int>> get_twin_primes(int n){
    vector<int> small_prime(n + 1), primes;
	vector<pair<int, int>> twin_primes;
    for(int i = 2 ; i <= n ; ++i){
        if(small_prime[ i ] == 0){
            small_prime[ i ] = i, primes.push_back(i);
			if(i > 2 && small_prime[ i - 2 ] == i - 2)
				twin_primes.emplace_back(i - 2, i);
		}
        for(int j = 0 ; j < primes.size() && primes[ j ] <= small_prime[ i ] && i * primes[ j ] <= n ; ++j)
            small_prime[ i * primes[ j ] ] = primes[ j ];
    }
    return twin_primes;
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	const int N = 20000000; // upper-bound found after some runs :)
	const vector<pair<int, int>> twin_primes = get_twin_primes(N);

	for(int n ; cin >> n ; )
		cout << "(" << twin_primes[ n - 1 ].first << ", " << twin_primes[ n - 1 ].second << ")" << endl;
	return 0;
}
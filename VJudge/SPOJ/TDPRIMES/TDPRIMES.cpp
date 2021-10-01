// Problem name: Printing some primes
// Problem link: https://vjudge.net/problem/SPOJ-TDPRIMES
// Submission link: https://vjudge.net/solution/32914137

#include <bits/stdc++.h>

using namespace std;

vector<int> get_primes(int n){
    vector<int> small_prime(n + 1), primes;
    for(int i = 2 ; i <= n ; ++i){
        if(small_prime[ i ] == 0)
            small_prime[ i ] = i, primes.push_back(i);
        for(int j = 0 ; j < primes.size() && primes[ j ] <= small_prime[ i ] && i * primes[ j ] <= n ; ++j)
            small_prime[ i * primes[ j ] ] = primes[ j ];
    }
    return primes;
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	const int N = 100000000;
	auto primes = get_primes(N);
	for(int i = 0 ; i < primes.size() ; i += 100)
		cout << primes[ i ] << endl;
	return 0;
}
// Problem name: Goldbach's Conjecture (II)
// Problem link: https://vjudge.net/problem/UVA-686
// Submission link: https://vjudge.net/solution/32914448

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

	const int N = (1 << 15);
	const vector<int> primes = get_primes(N);
	vector<int> ways(N << 1);
	for(int i = 0 ; i < primes.size() ; ++i)
		for(int j = i ; j < primes.size() ; ++j)
			++ways[ primes[ i ] + primes[ j ] ];
	for(int n ; cin >> n && n ; cout << ways[ n ] << endl);
	return 0;
}
// Problem name: Goldbach's Conjecture
// Problem link: https://vjudge.net/problem/UVA-543
// Submission link: https://vjudge.net/solution/32914399

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
    return small_prime;
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	const int N = 1000000;
	const vector<int> small_prime = get_primes(N);
	for(int n ; cin >> n && n ;){
		for(int i = 2, j = n - 2 ; ; ++i, --j){
			if(small_prime[ i ] == i && small_prime[ j ] == j){
				cout << n << " = " << i << " + " << j << endl;
				break;
			}
		}
	}
	return 0;
}
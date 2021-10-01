// Problem name: Summation of Four Primes
// Problem link: https://vjudge.net/problem/UVA-10168
// Submission link: https://vjudge.net/solution/32926841

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

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

pair<int, int> get_goldbach(const vector<int> &primes, int n){
	for(int i = 0, j ; ; ++i){
		j = lower_bound(primes.begin() + i, primes.end(), n - primes[ i ]) - primes.begin();
		if(primes[ i ] + primes[ j ] == n)
			return { primes[ i ], primes[ j ] };
	}
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	const int N = 10000000;
	const vector<int> primes = get_primes(N);

	for(int n ; cin >> n ; ){
		if(n <= 8)
			cout << (n == 8 ? "2 2 2 2" : "Impossible.") << endl;
		else{
			int lowest = 3 - (n & 1);
			int highest = primes[ upper_bound(primes.begin(), primes.end(), n - lowest - 4) - primes.begin() - 1 ];
			pair<int, int> goldbach = get_goldbach(primes, n - highest - lowest);
			cout << lowest << ' ' << highest << ' ' << goldbach.first << ' ' << goldbach.second << endl;
		}
	}
	return 0;
}
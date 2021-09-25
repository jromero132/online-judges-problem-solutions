// Problem name: Prime Generator
// Problem link: https://vjudge.net/problem/SPOJ-PRIME1
// Submission link: https://vjudge.net/solution/32893869

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> get_primes(int n){
    vector<int> least_prime(n + 1), primes;
    for(int i = 2 ; i <= n ; ++i){
        if(least_prime[ i ] == 0)
            least_prime[ i ] = i, primes.push_back(i);
        for(int j = 0 ; j < primes.size() && primes[ j ] <= least_prime[ i ] && i * primes[ j ] <= n ; ++j)
            least_prime[ i * primes[ j ] ] = primes[ j ];
    }
    return primes;
}

vector<int> get_primes(int l, int r){
    int lim = sqrt(r);
	vector<int> primes_up_to_lim = get_primes(lim);
	vector<char> prime(r - l + 1, 1);
	for(int p : primes_up_to_lim)
		for(ll i = max((ll)p * p, (ll)(l + p - 1) / p * p) ; i <= r ; i += p)
			prime[ i - l ] = 0;
	if(l == 1)
		prime[ 0 ] = false;
	vector<int> primes;
	for(int i = 0 ; i < prime.size() ; ++i)
		if(prime[ i ])
			primes.push_back(l + i);
	return primes;
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;
	for(cin >> t ; t-- ; ){
		int l, r;
		cin >> l >> r;
		vector<int> primes = get_primes(l, r);
		for(auto p : primes)
			cout << p << endl;
		if(t > 0)
			cout << endl;
	}
	return 0;
}
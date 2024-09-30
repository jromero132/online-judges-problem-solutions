// Problem name: Help Hanzo
// Problem link: https://vjudge.net/problem/LightOJ-1197
// Submission link: https://vjudge.net/solution/32960669

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

int get_primes(int l, int r){
    int lim = sqrt(r);
	vector<int> primes_up_to_lim = get_primes(lim);
	vector<bool> is_prime(r - l + 1, 1);
	for(int p : primes_up_to_lim)
		for(ll i = max((ll)p * p, (ll)(l + p - 1) / p * p) ; i <= r ; i += p)
			is_prime[ i - l ] = 0;
	if(l == 1)
		is_prime[ 0 ] = false;
	int primes = 0;
	for(int i = 0 ; i < is_prime.size() ; ++i)
		if(is_prime[ i ])
			++primes;
	return primes;
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	for(int k = 1 ; k <= t ; ++k){
		int l, r;
		cin >> l >> r;
		cout << "Case " << k << ": " << get_primes(l, r) << endl;
	}
	return 0;
}
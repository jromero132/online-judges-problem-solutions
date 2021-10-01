// Problem name: Prime Distance
// Problem link: https://vjudge.net/problem/UVA-10140
// Submission link: https://vjudge.net/solution/32946410

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> get_primes(int n){
    vector<int> small_prime(n + 1), primes;
    for(int i = 2 ; i <= n ; ++i){
        if(small_prime[ i ] == 0)
            small_prime[ i ] = i, primes.push_back(i);
        for(int j = 0 ; j < primes.size() && primes[ j ] <= small_prime[ i ] && (ll)i * primes[ j ] <= n ; ++j)
            small_prime[ i * primes[ j ] ] = primes[ j ];
    }
    return primes;
}

vector<int> get_primes(int l, int r){
    int lim = sqrt(r);
	vector<int> primes_up_to_lim = get_primes(lim);
	vector<bool> is_prime(r - l + 1, 1);
	for(int p : primes_up_to_lim)
		for(ll i = max((ll)p * p, ((ll)l + p - 1) / p * p) ; i <= r ; i += p)
			is_prime[ i - l ] = 0;
	if(l == 1)
		is_prime[ 0 ] = false;
	vector<int> ans(4, -1);
	for(int i = 0, last = -1 ; i < is_prime.size() ; ++i)
		if(is_prime[ i ]){
			if(last > -1){
				if(ans[ 0 ] == -1 || i - last < ans[ 1 ] - ans[ 0 ])
					ans[ 0 ] = l + last, ans[ 1 ] = l + i;
				if(ans[ 2 ] == -1 || i - last > ans[ 3 ] - ans[ 2 ])
					ans[ 2 ] = l + last, ans[ 3 ] = l + i;
			}
			last = i;
		}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	for(int l, r ; cin >> l >> r ; ){
		vector<int> ans = get_primes(l, r);
		if(ans[ 0 ] == -1)
			cout << "There are no adjacent primes." << endl;
		else
			cout << ans[ 0 ] << ',' << ans[ 1 ] << " are closest, " << ans[ 2 ] << ',' << ans[ 3 ] << " are most distant." << endl;
	}
	return 0;
}
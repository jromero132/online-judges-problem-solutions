// Problem name: Less Prime
// Problem link: https://vjudge.net/problem/UVA-10852
// Submission link: https://vjudge.net/solution/32960150

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> get_primes(int n){
    vector<bool> is_prime(n + 1, 1);
    vector<int> primes;
	is_prime[ 0 ] = is_prime[ 1 ] = 0;
    if(n >= 2){
        primes.push_back(2);
		for(int i = 4 ; i <= n ; i += 2)
			is_prime[ i ] = 0;
	}
    for(int i = 3 ; i <= n ; i += 2)
        if(is_prime[ i ]){
            primes.push_back(i);
            for(ll j = (ll)i * i ; j <= n ; j += 2 * i)
                is_prime[ j ] = 0;
        }
    return primes;
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	const int N = 10000;
	const vector<int> primes = get_primes(N);

	int t;
	for(cin >> t ; t-- ; ){
		int n;
		cin >> n;
		int ans = 0, value = 0;
		for(int i = 0, p, v ; i < primes.size() && primes[ i ] <= n ; ++i){
			p = n / primes[ i ];
			v = n - p * primes[ i ];
			if(v > value)
				value = v, ans = primes[ i ];
		}
		cout << ans << endl;
	}
	return 0;
}
// Problem name: Prime Cuts
// Problem link: https://vjudge.net/problem/UVA-406
// Submission link: https://vjudge.net/solution/32914290

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
	primes.insert(primes.begin(), 1);
    return primes;
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n, c;
	while(cin >> n >> c){
		vector<int> primes = get_primes(n);
		cout << n << ' ' << c << ':';
		for(int low = max(0, (int)(primes.size() + 1) / 2 - c), high = min(primes.size(), primes.size() / 2 + c) ; low < high ; ++low)
			cout << ' ' << primes[ low ];
		cout << endl << endl;
	}
	return 0;
}
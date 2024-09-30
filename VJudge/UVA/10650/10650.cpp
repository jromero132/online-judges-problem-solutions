// Problem name: Determinate Prime
// Problem link: https://vjudge.net/problem/UVA-10650
// Submission link: https://vjudge.net/solution/32958906

#include <bits/stdc++.h>

using namespace std;

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
            for(int j = i * i ; j <= n ; j += 2 * i)
                is_prime[ j ] = 0;
        }
    return primes;
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	const int MIN_SIZE = 3;
	const int N = 32500;
	const vector<int> primes = get_primes(N);

	for(int l, r ; cin >> l >> r && l != 0 || r != 0 ; ){
		if(l > r)
			swap(l, r);
		l = lower_bound(primes.begin(), primes.end(), l) - primes.begin();
		r = upper_bound(primes.begin(), primes.end(), r) - primes.begin();
		for(int i = l ; i + MIN_SIZE <= r ; ++i){
			vector<int> ans{ primes[ i ], primes[ i + 1 ]};
			for(int k = 2 ; k < MIN_SIZE ; ++k){
				if(primes[ i + k ] - primes[ i + k - 1 ] != primes[ i + k - 1 ] - primes[ i + k - 2 ])
					break;
				ans.push_back(primes[ i + k ]);
			}
			if(ans.size() == MIN_SIZE){
				bool ok = i != l || (i > 0 && primes[ i + 1 ] - primes[ i ] != primes[ i ] - primes[ i - 1 ]);
				for(i += MIN_SIZE - 1 ; i + 1 < r && primes[ i + 1 ] - primes[ i ] == primes[ i ] - primes[ i - 1 ] ; ++i)
					ans.push_back(primes[ i + 1 ]);
				if(ok && (i + 1 != r || primes[ i + 1 ] - primes[ i ] != primes[ i ] - primes[ i - 1 ])){
					cout << ans[ 0 ];
					for(int j = 1 ; j < ans.size() ; ++j)
						cout << ' ' << ans[ j ];
					cout << endl;
				}
				--i;
			}
		}
	}
	return 0;
}
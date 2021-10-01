// Problem name: Anagrammatic Primes
// Problem link: https://vjudge.net/problem/UVA-897
// Submission link: https://vjudge.net/solution/32914826

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<bool> get_primes(int n){
    vector<bool> prime(n + 1, 1);
    vector<int> primes;
	prime[ 0 ] = prime[ 1 ] = 0;
    if(n >= 2){
        primes.push_back(2);
		for(int i = 4 ; i <= n ; i += 2)
			prime[ i ] = 0;
	}
    for(int i = 3 ; i <= n ; i += 2)
        if(prime[ i ]){
            primes.push_back(i);
            for(ll j = (ll)i * i ; j <= n ; j += 2 * i)
                prime[ j ] = 0;
        }
    return prime;
}

set<int> get_anagrammatic_primes(const vector<bool> &prime){
	set<int> anagrammatic_primes;
	vector<bool> visited(prime.size());
	for(int i = 2 ; i < prime.size() ; ++i){
		if(prime[ i ] && !visited[ i ]){
			int p = i;
			bool ok = true;
			string s = to_string(p);
			sort(s.begin(), s.end());
			vector<int> seq;
			do{
				p = atoi(s.c_str());
				if(p < prime.size()){
					seq.push_back(p);
					visited[ p ] = 1;
					if(!prime[ p ])
						ok = false;
				}
			}while(next_permutation(s.begin(), s.end()));
			if(ok){
				for(auto p : seq)
					anagrammatic_primes.insert(p);
			}
		}
	}
	return anagrammatic_primes;
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	const int N = 10000000;
	const vector<bool> prime = get_primes(N);
	const set<int> anagrammatic_primes = get_anagrammatic_primes(prime);
	for(int n ; cin >> n && n ; ){
		auto it = anagrammatic_primes.lower_bound(n + 1);
		cout << (it == anagrammatic_primes.end() || *it >= (int)pow(10, (int)log10(n) + 1) ? 0 : *it) << endl;
	}
	return 0;
}
// Problem name: Prime Generator
// Problem link: https://vjudge.net/problem/SPOJ-PRIME1
// Submission link: https://vjudge.net/solution/32893147

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> get_primes(int n){
	set<pair<int, int>> s({{ 4, 2 }});
    vector<int> primes;
	if(n >= 2)
		primes.push_back(2);
    for(int i = 3 ; i <= n ; ++i){
		auto it = s.lower_bound({ i, 0 });
		if((it -> first) > i){
			primes.push_back(i);
			if((ll)i * i < n)
				s.insert({ i * i, 2 * i });
		}
		else{
			while((it -> first) == i){
				s.insert({ (it -> first) + (it -> second), it -> second });
				s.erase(it);
				it = s.lower_bound({ i, 0 });
			}
		}
	}
    return primes;
}

vector<int> get_primes(int l, int r){
    int lim = sqrt(r);
	vector<char> prime(r - l + 1, 1);
	for(int p = 2 ; p <= lim ; ++p)
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
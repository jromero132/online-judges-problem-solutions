// Problem name: Jumping Champion
// Problem link: https://vjudge.net/problem/UVA-914
// Submission link: https://vjudge.net/solution/32926004

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

vector<vector<int>> get_frequencies(vector<int> primes){
	const int MAX_DIFF = 114; // calculated after running get_primes first;
	vector<vector<int>> freq(primes.size(), vector<int>(MAX_DIFF, 0));
	for(int i = 1 ; i < primes.size() ; ++i){
		for(int j = 0 ; j < MAX_DIFF ; ++j)
			freq[ i ][ j ] = freq[ i - 1 ][ j ];
		++freq[ i ][ primes[ i ] - primes[ i - 1 ] - 1 ];
	}
	return freq;
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	const int N = 1000000;
	const vector<int> primes = get_primes(N);
	const vector<vector<int>> freq = get_frequencies(primes);

	int t;
	for(cin >> t ; t-- ; ){
		int l, r;
		cin >> l >> r;
		int p1 = lower_bound(primes.begin(), primes.end(), l) - primes.begin();
		int p2 = upper_bound(primes.begin(), primes.end(), r) - primes.begin();
		int ans = 0, f_ans = 0;
		bool unique = false;
		if(p1 < p2){
			for(int i = 0, f ; i < freq[ p1 ].size() ; ++i){
				f = freq[ p2 - 1 ][ i ] - freq[ p1 ][ i ];
				if(f > f_ans)
					ans = i + 1, f_ans = f, unique = true;
				else if(f == f_ans)
					unique = false;
			}
		}
		if(unique)
			cout << "The jumping champion is " << ans << endl;
		else
			cout << "No jumping champion" << endl;
	}
	return 0;
}
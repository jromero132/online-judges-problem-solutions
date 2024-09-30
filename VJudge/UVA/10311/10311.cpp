// Problem name: Goldbach and Euler
// Problem link: https://vjudge.net/problem/UVA-10311
// Submission link: https://vjudge.net/solution/32959031

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

pair<int, int> get_goldbach(int n, const vector<int> &primes){
	for(auto right = upper_bound(primes.begin(), primes.end(), n  / 2), left = right - 1 ; left >= primes.begin() && right != primes.end() ; --left){
		while(*left + *right < n)
			++right;
		if(*left + *right == n)
			return { *left, *right };
	}
	return { -1, -1 };
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	const int N = 100000000;
	const vector<int> primes = get_primes(N);

	for(int n ; cin >> n ; ){
		pair<int, int> ans = n < 4 || (n & 1 && *lower_bound(primes.begin(), primes.end(), n - 2 ) != n - 2) ? make_pair(-1, -1) : (n & 1 ? make_pair(2, n - 2) : get_goldbach(n, primes));
		if(ans.first == -1)
			cout << n << " is not the sum of two primes!" << endl;
		else
			cout << n << " is the sum of " << ans.first << " and " << ans.second << "." << endl;
	}
	return 0;
}
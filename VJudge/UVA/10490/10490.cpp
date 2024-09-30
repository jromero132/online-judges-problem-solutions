// Problem name: Mr. Azad and his Son!!!!!
// Problem link: https://vjudge.net/problem/UVA-10490
// Submission link: https://vjudge.net/solution/32962433

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	const set<int> prime_numbers{ 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31 };
	const set<ll> perfect_numbers{ 6, 28, 496, 8128, 33550336, 8589869056, 137438691328, 2305843008139952128 };

	for(int n ; cin >> n && n ; ){
		ll p = (1LL << n - 1) * ((1LL << n) - 1);
		if(perfect_numbers.find(p) != perfect_numbers.end())
			cout << "Perfect: " << p << "!" << endl;
		else if(prime_numbers.find(n) != prime_numbers.end())
			cout << "Given number is prime. But, NO perfect number is available." << endl;
		else
			cout << "Given number is NOT prime! NO perfect number is available." << endl;
	}
	return 0;
}
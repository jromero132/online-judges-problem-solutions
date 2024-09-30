// Problem name: Little Girl and Maximum XOR
// Problem link: https://vjudge.net/problem/CodeForces-276D
// Submission link: https://vjudge.net/solution/33000350

#include <bits/stdc++.h>

#define clz __builtin_clzll
#define first_bit_on(x) (8 * sizeof(x) - clz(x) - 1)

using namespace std;

typedef unsigned long long ull;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	ull l, r;
	cin >> l >> r;
	ull a = 0, b = 0;
	for(ull mask = 1ULL << first_bit_on(r) ; mask > 0 ; mask >>= 1){
		bool used = false;
		if((a | mask) <= l)
			a |= mask, used = true;
		if((b | mask) <= l)
			b |= mask, used = true;
		if(!used){
			if((a | mask) <= r)
				a |= mask;
			else if((b | mask) <= r)
				b |= mask;
		}
	}
	cout << (a ^ b) << endl;
	return 0;
}
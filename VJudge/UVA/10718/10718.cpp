// Problem name: Bit Mask
// Problem link: https://vjudge.net/problem/UVA-10718
// Submission link: https://vjudge.net/solution/33000096

#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	const int size = 32;

	for(ull n, l, r, m = 0 ; cin >> n >> l >> r ; cout << m << endl, m = 0)
		for(ull k = 1ULL << (size - 1) ; k > 0 ; k >>= 1)
			if(((~n & k) && (m | k) <= r) || ((n & k) && (m | k) <= l))
				m |= k;
	return 0;
}
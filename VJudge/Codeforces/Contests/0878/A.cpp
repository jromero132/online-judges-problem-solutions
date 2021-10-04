// Problem name: Short Program
// Problem link: https://vjudge.net/problem/CodeForces-878A
// Submission link: https://vjudge.net/solution/32999899

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	const int bits = 10;
	const int input1 = 0, input2 = (1 << bits) - 1; // could be any two values a, b such that a & b = 0 and a | b = 2^bits - 1

	int n, n1 = input1, n2 = input2;
	for(cin >> n ; n-- ; ){
		char c;
		int x;
		cin >> c >> x;
		switch(c)
		{
		case '&':
			n1 &= x;
			n2 &= x;
			break;

		case '|':
			n1 |= x;
			n2 |= x;
			break;

		default:
			n1 ^= x;
			n2 ^= x;
			break;
		}
	}
	int and_cmd = 0, xor_cmd = 0;
	for(int k = 1 << (bits - 1), before1, before2, after1, after2 ; k > 0 ; k >>= 1){
		before1 = input1 & k;
		before2 = input2 & k;
		after1 = n1 & k;
		after2 = n2 & k;

		if((before1 ^ after1) == (before2 ^ after2))
			and_cmd |= k;
		if((before1 ^ after1 && before2 > 0) || (before2 ^ after2 && before1 > 0))
			xor_cmd |= k;
	}
	vector<pair<char, int>> sol;
	if(and_cmd != (1 << bits) - 1)
		sol.emplace_back('&', and_cmd);
	if(xor_cmd != 0)
		sol.emplace_back('^', xor_cmd);
	cout << sol.size() << endl;
	for(auto s : sol)
		cout << s.first << ' ' << s.second << endl;
	return 0;
}
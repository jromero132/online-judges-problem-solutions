// Problem name: Latin Squares
// Problem link: https://codeforces.com/gym/101652/problem/O
// Submission link: https://codeforces.com/gym/101652/submission/43703698

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

typedef long long ll;

inline int get_number(char c){
	return c >= 48 && c <= 57 ? c - 48 : c - 55;
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);

#ifdef JoseA132
	freopen("01.in", "r", stdin);
#endif

	int n;
	while(cin >> n){
		bool latin_square = 1, reduced = 1;
		vector<string> square(n);
		for(auto &s : square)
			cin >> s;
		for(int i = 0 ; i < n ; ++i){
			ll row = 0LL, col = 0LL;
			for(int j = 0 ; j < n ; ++j)
				row |= (1LL << get_number(square[ i ][ j ])), col |= (1LL << get_number(square[ j ][ i ]));
			latin_square &= !((row ^ col) | (row ^ ((1LL << n) - 1)));
			if(i)
				reduced &= (square[ i ][ 0 ] > square[ i - 1 ][ 0 ] && square[ 0 ][ i ] > square[ 0 ][ i - 1 ]);
		}
		cout << (latin_square ? (reduced ? "Reduced" : "Not Reduced") : "No") << endl;
	}
	return 0;
}
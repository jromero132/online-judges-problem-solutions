// Problem name: Balloons (A)
// Problem link: https://codeforces.com/gym/101401/problem/F
// Submission link: https://codeforces.com/gym/101401/submission/43706570

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int get_number(char c){
	switch(c){
	case 'B':
		return 0;
	case 'G':
		return 1;
	case 'R':
		return 2;
	}
	return -1;
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);

#ifdef JoseA132
	freopen("01.in", "r", stdin);
#endif

	string s, b = "BGR";
	cin >> s;
	if(s.length() == 3){
		cout << 0 << endl;
		return 0;
	}
	int mask1 = 0, mask2 = 0;
	for(int i = 0 ; i < 3 ; ++i)
		mask1 |= (1 << get_number(s[ i ])), mask2 |= (1 << get_number(s[ s.length() - i - 1 ]));
	if(mask1 == 7 || mask2 == 7){
		cout << 1 << endl;
		return 0;
	}
	if(((1 << get_number(s[ 0 ])) | (1 << get_number(s[ 1 ])) | (1 << get_number(s[ s.length() - 1 ]))) == 7 || ((1 << get_number(s[ 0 ])) | (1 << get_number(s[ s.length() - 2 ])) | (1 << get_number(s[ s.length() - 1 ]))) == 7){
		cout << 2 << endl;
		return 0;
	}
	for(int i = 2 ; s[ i ] ; ++i){
		if(((1 << get_number(s[ i - 2 ])) | (1 << get_number(s[ i - 1 ])) | (1 << get_number(s[ i ]))) == 7){
			cout << 2 << endl;
			return 0;
		}
	}
	if(s[ 0 ] != s[ 1 ] || s[ s.length() - 2 ] != s[ s.length() - 1 ]){
		cout << 3 << endl;
		return 0;
	}
	for(int i = 1 ; s[ i ] ; ++i){
		if(s[ i - 1 ] != s[ i ] && ((s[ i - 1 ] != s[ 0 ] && s[ i ] != s[ 0 ]) || (s[ i - 1 ] != s[ s.length() - 1 ] && s[ i ] != s[ s.length() - 1 ]))){
			cout << 3 << endl;
			return 0;
		}
	}
	cout << 4 << endl;
	return 0;
}
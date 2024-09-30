// Problem name: Divisibility by Eight
// Problem link: https://vjudge.net/problem/CodeForces-550C
// Submission link: https://vjudge.net/solution/16582745

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);

#ifdef JoseA132
	freopen("01.in", "r", stdin);
#endif

	string s;
	cin >> s;
	s = "00" + s;
	for(int i = 0, n = s.length() ; i < n ; ++i)
		for(int j = i + 1 ; j < n ; ++j)
			for(int k = j + 1, num ; k < n ; ++k){
				num = 100 * (s[ i ] - '0') + 10 * (s[ j ] - '0') + (s[ k ] - '0');
				if(!(num & 7)){
					cout << "YES" << endl << num << endl;
					return 0;
				}
			}
	cout << "NO" << endl;
	return 0;
}
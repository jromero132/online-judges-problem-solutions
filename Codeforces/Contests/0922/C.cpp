// Problem name: Cave Painting
// Problem link: https://codeforces.com/contest/922/problem/C
// Submission link: https://codeforces.com/contest/922/submission/35035827

#include <iostream>

#define MAX ((int)42)

using namespace std;

typedef long long ll;

bool check[ MAX ];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll n, k;
	cin >> n >> k;
	if(k >= 43){
		cout << "No";
		return 0;
	}
	for(int i = 1 ; i <= k ; i++){
		if(check[ n % i ]){
			cout << "No";
			return 0;
		}
		check[ n % i ] = 1;
	}
	cout << "Yes";
	return 0;
}
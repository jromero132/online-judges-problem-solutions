// Problem name: MaratonIME helps Pablito
// Problem link: https://codeforces.com/gym/101744/problem/A
// Submission link: https://codeforces.com/gym/101744/submission/43082494

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);

	int t;
	ll a, b;
	for(cin >> t ; t-- ; ){
		cin >> a >> b;
		cout << (__gcd(a, b) == 1 ? "Nao" : "Sim") << endl;
	}
	return 0;
}
// Problem name: MaratonIME goes rowing
// Problem link: https://codeforces.com/gym/101744/problem/G
// Submission link: https://codeforces.com/gym/101744/submission/43083790

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);

	string s;
	cin >> s;
	int cnt = 0;
	for(int i = 0 ; s[ i ] ; i++){
		cnt += (s[ i ] == 'A' ? 1 : -1);
		if(cnt == -1){
			cout << "Nao" << endl;
			return 0;
		}
	}
	cout << (cnt == 0 ? "Sim" : "Nao") << endl;
	return 0;
}
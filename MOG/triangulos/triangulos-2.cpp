// Problem name: C - Triángulos
// Problem link: https://matcomgrader.com/problem/4700/triangulos/
// Submission link: https://matcomgrader.com/submission/125428/

#include <bits/stdc++.h>

#define pb push_back
#define endl '\n'

using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);

	int n;
	vector<int> num;
	while(cin >> n && n)
		num.pb(n);
	sort(num.begin(), num.end());
	for(int i = 2 ; i < num.size() ; i++)
		if(num[ i - 2 ] + num[ i - 1 ] > num[ i ]){
			cout << num[ i - 2 ] << ' ' << num[ i - 1 ] << ' ' << num[ i ] << endl;
			return 0;
		}
	cout << "NO" << endl;
	return 0;
}
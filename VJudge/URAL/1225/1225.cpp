// Problem name: Flags
// Problem link: https://vjudge.net/problem/URAL-1225
// Submission link: https://vjudge.net/solution/16130815

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);

#ifdef JoseA132
	freopen("01.in", "r", stdin);
#endif

	int n;
	cin >> n;
	ll last = 1, cur = 1;
	for(int i = 2 ; i < n ; ++i)
		swap(last += cur, cur);
	cout << (cur << 1) << endl;
	return 0;
}
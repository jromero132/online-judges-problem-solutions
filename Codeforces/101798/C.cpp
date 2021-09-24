// Problem name: Forest (A) - Egg
// Problem link: https://codeforces.com/gym/101798/problem/C
// Submission link: https://codeforces.com/gym/101798/submission/43222206

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

typedef long long ll;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0);

/*#ifdef JoseA132
	freopen("01.in", "r", stdin);
#endif*/

	int n;

	cin >> n;

	int may = -1;
	int ans = 0;

	for(int i = 0;i < n;i ++){
		int num;
		cin >> num;
		if(num > may){
			ans ++;
			may = num;
		}
	}

	cout << ans << "\n";

	return 0;
}
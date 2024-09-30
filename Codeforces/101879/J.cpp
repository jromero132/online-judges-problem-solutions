// Problem name: Meme Wars
// Problem link: https://codeforces.com/gym/101879/problem/J
// Submission link: https://codeforces.com/gym/101879/submission/45336415

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

typedef long long ll;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0);

	int n;
	cin >> n;
	string ans = "";
	for(int i = 0 ; ans.length() < n ; ++i)
		ans = ans + (char)(i + 'a') + ans;
	cout << ans[ --n ] << endl;
	return 0;
}
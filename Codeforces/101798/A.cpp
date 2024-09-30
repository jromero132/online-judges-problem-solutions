// Problem name: Two Fashillows
// Problem link: https://codeforces.com/gym/101798/problem/A
// Submission link: https://codeforces.com/gym/101798/submission/43221745

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

typedef long long ll;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0);

#ifdef JoseA132
	freopen("01.in", "r", stdin);
#endif

	int d, w, m;
	cin >> d >> w >> m;
	cout << (d >= w + m || w > d ? "good luck" : "see you next semester");
	return 0;
}
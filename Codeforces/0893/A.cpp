// Problem name: Chess For Three
// Problem link: https://codeforces.com/contest/893/problem/A
// Submission link: https://codeforces.com/contest/893/submission/32581507

#include <bits/stdc++.h>

#define MAX (int)(1e5 + 1)
#define MOD (int)(3)
#define mod(x) (((x) % MOD + MOD) % MOD)
#define endl '\n'

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	int n, now, p1 = 1, p2 = 2;
	for(cin >> n ; n-- ; ){
		cin >> now;
		if(now != p1 && now != p2){
			cout << "NO";
			return 0;
		}
		if(now != p1)
			p2 = p1, p1 = now;
		if(p1 == 1)
			p2 = (p2 == 2 ? 3 : 2);
		else if(p1 == 2)
			p2 = (p2 == 1 ? 3 : 1);
		else
			p2 = (p2 == 1 ? 2 : 1);
	}
	cout << "YES";
    return 0;
}
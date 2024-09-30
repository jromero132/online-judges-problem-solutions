// Problem name: Table Tennis
// Problem link: https://codeforces.com/contest/879/problem/B
// Submission link: https://codeforces.com/contest/879/submission/31925027

#include <iostream>

using namespace std;

typedef long long ll;

int n;
ll k;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
	int win = 0, v, x;
	cin >> v;
	for(int i = 1 ; i < n ; i++){
		cin >> x;
		if(v > x)
			win++;
		else
			v = x, win = 1;
		if(win == k)
			break;
	}
	cout << v;
    return 0;
}
// Problem name: Driving Test
// Problem link: https://codeforces.com/contest/845/problem/D
// Submission link: https://codeforces.com/contest/845/submission/43051113

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);

	int n, t, now, s, ans = 0;
	cin >> n;
	stack<bool> overtake;
	stack<int> speed;
	speed.push(300);
	overtake.push(1);
	for(int i = 0 ; i < n ; i++){
		cin >> t;
		switch(t){
		case 1:
			cin >> s;
			while(speed.top() < s)
				ans++, speed.pop();
			continue;

		case 2:
			while(!overtake.top())
				ans++, overtake.pop();
			continue;

		case 3:
			cin >> now;
			if(now >= s)
				speed.push(now);
			else
				ans++;
			continue;

		case 4:
			overtake.push(1);
			continue;

		case 5:
			speed.push(300);
			continue;

		default:
			overtake.push(0);
		}
	}
	cout << ans << endl;
	return 0;
}
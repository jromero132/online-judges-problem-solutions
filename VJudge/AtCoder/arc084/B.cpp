// Problem name: Small Multiple
// Problem link: https://vjudge.net/problem/AtCoder-arc084_b
// Submission link: https://vjudge.net/solution/32882930

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int k;
	cin >> k;
	deque<pair<int, int>> q({{ 1, 1 }});
	vector<bool> visited(k);
	while(true){
		int pos = q.front().first, sum = q.front().second;
		q.pop_front();
		if(pos == 0){
			cout << sum;
			break;
		}
		visited[ pos ] = true;
		int n1 = (pos + 1) % k, n10 = pos * 10 % k;
		if(!visited[ n1 ])
			q.push_back({ n1, sum + 1 });
		if(!visited[ n10 ])
			q.push_front({ n10, sum });
	}
	return 0;
}
// Problem name: Fibsieve's Fantabulous Birthday
// Problem link: https://vjudge.net/problem/LightOJ-1008
// Submission link: https://vjudge.net/solution/32877996

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	for(int k = 1 ; k <= t ; ++k){
		ll n;
		cin >> n;
		ll block = (int)sqrt(n - 1) + 1;
		ll low = (block - 1) * (block - 1);
		ll high = block * block;
		ll mid = (high + low) >> 1;
		int x, y;
		if(block & 1){
			if(n <= mid)
				x = block, y = block - mid + n - 1;
			else
				x = high - n + 1, y = block;
		}
		else{
			if(n <= mid)
				x = block + n - mid - 1, y = block;
			else
				x = block, y = high - n + 1;
		}
		cout << "Case " << k << ": " << x << ' ' << y << endl;
	}
}
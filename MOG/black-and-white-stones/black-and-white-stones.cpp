// Problem name: B - Black and white stones
// Problem link: https://matcomgrader.com/problem/9304/black-and-white-stones/
// Submission link: https://matcomgrader.com/submission/123373/

#include <bits/stdc++.h>

#define MAX ((int)500000)
#define endl '\n'

using namespace std;

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll ans = 0;
	int a, b, left, right = 0;
	string s;
	cin >> a >> b >> s;
	for(int i = 0 ; s[ i ] ; i++)
		right += (s[ i ] == 'B');
	left = right - 1;
	while(left >= 0 && s[ right ]){
		if(s[ left ] == 'B'){
			left--;
			continue;
		}
		if(s[ right ] == 'W'){
			right++;
			continue;
		}
        ans += min((ll)a, ((ll)(right - left)) * (a - b));
        left--;
        right++;
	}
	cout << ans << endl;
	return 0;
}
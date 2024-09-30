// Problem name: Divisibility by 25
// Problem link: https://vjudge.net/problem/CodeForces-988E
// Submission link: https://vjudge.net/solution/16114447

#include <bits/stdc++.h>

#define INF ((int)1e9)
#define endl '\n'

using namespace std;

int put(string s1, string s2){
	if(s1.length() < s2.length())
		return INF;
	int ans = 0;
	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());
	for(int i = 0 ; i < s2.length() ; ++i){
		bool ok = 0;
		for(int j = i ; j < s1.length() ; ++j){
			if(s1[ j ] == s2[ i ]){
				for(int k = j - 1 ; k >= i ; --k, ++ans)
					swap(s1[ k ], s1[ k + 1 ]);
				ok = 1;
				break;
			}
		}
		if(!ok)
			return INF;
	}
	for(int i = s1.length() - 1 ; s1[ i ] == '0' ; ++ans, --i);
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

#ifdef JoseA132
	freopen("01.in", "r", stdin);
#endif

	string s;
	cin >> s;
	int ans = min(min(min(put(s, "00"), put(s, "25")), put(s, "50")), put(s, "75"));
	cout << (ans == INF ? -1 : ans) << endl;
	return 0;
}
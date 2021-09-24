// Problem name: Finding Missing Cards
// Problem link: https://vjudge.net/problem/Aizu-ITP1_6_B
// Submission link: https://vjudge.net/solution/12786176

#include <bits/stdc++.h>

#define CARDS ((int)4)
#define mp make_pair
#define F first
#define S second
#define endl '\n'

using namespace std;

typedef pair<int, int> pii;

char type[] = { 'S', 'H', 'C', 'D' };

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	set<pii> card;
	for(int i = 0 ; i < CARDS ; i++)
		for(int j = 1 ; j <= 13 ; j++)
			card.insert(mp(i, j));
	int n, v;
	char c;
	for(cin >> n ; n-- ; ){
		cin >> c >> v;
		for(int i = 0 ; i < CARDS ; i++)
			if(type[ i ] == c){
				card.erase(mp(i, v));
				break;
			}
	}
	for(auto x : card)
		cout << type[ x.F ] << ' ' << x.S << endl;
	return 0;
}
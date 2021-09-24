// Problem name: Finding Missing Cards
// Problem link: https://vjudge.net/problem/Aizu-ITP1_6_B
// Submission link: https://vjudge.net/solution/12786175

#include <bits/stdc++.h>

#define CARDS ((int)4)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define endl '\n'

using namespace std;

typedef pair<int, int> pii;

const char type[] = { 'S', 'H', 'C', 'D' };

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<pii> card;
	for(int i = 0 ; i < CARDS ; i++)
		for(int j = 1 ; j <= 13 ; j++)
			card.pb(mp(i, j));
	int n, v, len = 52;
	char c;
	pii now;
	for(cin >> n ; n-- ; ){
		cin >> c >> v;
		for(int i = 0 ; i < CARDS ; i++)
			if(type[ i ] == c){
				now = mp(i, v);
				break;
			}
		for(int i = 0 ; i < len ; i++)
			if(card[ i ] == now){
				card.erase(card.begin() + i);
				len--;
				break;
			}
	}
	for(int i = 0 ; i < len ; i++)
		cout << type[ card[ i ].F ] << ' ' << card[ i ].S <<  endl;
	return 0;
}
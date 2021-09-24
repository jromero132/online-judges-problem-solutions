// Problem name: Ouths and Crosses
// Problem link: https://vjudge.net/problem/URAL-1195
// Submission link: https://vjudge.net/solution/12821162

#include <bits/stdc++.h>

//#define endl '\n'

using namespace std;

const int n = 3;

char board[ n ][ n ];

int check(){
	bool d1 = 1, d2 = 1;
	for(int i = 0 ; i < n ; i++){
		if(board[ 0 ][ i ] == board[ 1 ][ i ] && board[ 1 ][ i ] == board[ 2 ][ i ])
			return board[ 0 ][ i ] == 'X' ? 1 : -1;
		if(board[ i ][ 0 ] == board[ i ][ 1 ] && board[ i ][ 1 ] == board[ i ][ 2 ])
			return board[ i ][ 0 ] == 'X' ? 1 : -1;
		d1 &= (board[ i ][ i ] == board[ 0 ][ 0 ]);
		d2 &= (board[ i ][ n - i - 1 ] == board[ 0 ][ 2 ]);
	}
	if(d1)
		return board[ 0 ][ 0 ] == 'X' ? 1 : -1;
	if(d2)
		return board[ 0 ][ 2 ] == 'X' ? 1 : -1;
	return 0;
}

int win(int plays){
	int ans = check();
	if(ans)
		return ans;
	if(!plays)
		return 0;
	ans = (plays & 1 ? -1 : 1);
	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < n ; j++)
			if(board[ i ][ j ] == '#'){
				if(plays & 1){
					board[ i ][ j ] = 'X';
					ans = max(win(plays - 1), ans);
				}
				else{
					board[ i ][ j ] = 'O';
					ans = min(win(plays - 1), ans);
				}
				board[ i ][ j ] = '#';
			}
    return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < n ; j++)
        	cin >> board[ i ][ j ];
    int w = win(3);
    if(w == 1)
        cout << "Crosses win" << endl;
    else if(w == -1)
		cout << "Ouths win" << endl;
    else
        cout << "Draw" << endl;
	return 0;
}
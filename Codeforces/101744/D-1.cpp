// Problem name: MaratonIME plays Chess
// Problem link: https://codeforces.com/gym/101744/problem/D
// Submission link: https://codeforces.com/gym/101744/submission/43094052

#include <bits/stdc++.h>

#define ROW ((int)8)
#define COLUMN ((int)8)
#define F first
#define S second
#define endl '\n'

using namespace std;

typedef pair<int, int> pii;

vector<vector<pii>> dir = {
		{ { -1, -2 }, { -2, -1 }, {-2, 1 }, { -1, 2 }, { 1, 2 }, { 2, 1 }, { 2, -1 }, { 1, -2 } },
		{ { -1, 0 }, { 0, -1 }, { 0, 1 }, { 1, 0 } },
		{ { -1, -1 }, { -1, 1 }, { 1, -1 }, { 1, 1 } },
		{ { -1, -1 }, { -1, 0 }, { -1, 1 }, { 0, -1 }, { 0, 1 }, { 1, -1 }, { 1, 0 }, { 1, 1 } }
};

char board[ ROW ][ COLUMN ];

int dir_pos(char c){
	switch(c){
	case 'c':
		return 0;

	case 't':
		return 1;

	case 'b':
		return 2;

	case 'r':
	case 'k':
		return 3;

	default:
		return -1;
	}
}

bool is_valid(int r, int c){
	return r >= 0 && r < ROW && c >= 0 && c < COLUMN;
}

bool pawn(int i, int j, int r, int c){
	return i - 1 == r && abs(j - c) == 1;
}

bool attack1(int i, int j, int r, int c, int d){
	for(int k = 0 ; k < dir[ d ].size() ; k++)
		if(i + dir[ d ][ k ].F == r && j + dir[ d ][ k ].S == c)
			return 1;
	return 0;
}

bool attack2(int i, int j, int r, int c, int d){
	for(int k = 0 ; k < dir[ d ].size() ; k++){
		int ii = i + dir[ d ][ k ].F, jj = j + dir[ d ][ k ].S;
		while(is_valid(ii, jj)){
			if(ii == r && jj == c)
				return 1;

			if(board[ ii ][ jj ] != '.')
				break;

			ii += dir[ d ][ k ].F;
			jj += dir[ d ][ k ].S;
		}
	}
	return 0;
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);

	for(int i = 0 ; i < ROW ; i++)
		for(int j = 0 ; j < COLUMN ; j++)
			cin >> board[ i ][ j ];
	string pos;
	cin >> pos;
	int r = ROW + 48 - pos[ 1 ], c = pos[ 0 ] - 97;
	if(!(board[ r ][ c ] >= 65 && board[ r ][ c ] <= 90)){
		cout << "Nao" << endl;
		return 0;
	}
	for(int i = 0 ; i < ROW ; i++)
		for(int j = 0 ; j < COLUMN ; j++)
			if(board[ i ][ j ] == 'p' && pawn(i, j, r, c)){
				cout << "Sim" << endl;
				return 0;
			}
			else if((board[ i ][ j ] == 'c' || board[ i ][ j ] == 'k') && attack1(i, j, r, c, dir_pos(board[ i ][ j ]))){
				cout << "Sim" << endl;
				return 0;
			}
			else if((board[ i ][ j ] == 't' || board[ i ][ j ] == 'b' || board[ i ][ j ] == 'r') && attack2(i, j, r, c, dir_pos(board[ i ][ j ]))){
				cout << "Sim" << endl;
				return 0;
			}
	cout << "Nao" << endl;
	return 0;
}
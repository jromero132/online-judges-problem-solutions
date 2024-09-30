// Problem name: MaratonIME plays Chess
// Problem link: https://vjudge.net/problem/Gym-100985D
// Submission link: https://vjudge.net/solution/16014249

#include <bits/stdc++.h>

#define ROW ((int)8)
#define COLUMN ((int)8)
#define F first
#define S second
#define endl '\n'

using namespace std;

typedef pair<int, int> pii;
const vector<vector<pii>> dir = {
	{ { -2, -1 }, { -2, 1 }, { -1, -2 }, { -1, 2 }, { 1, -2 }, { 1, 2 }, { 2, -1 }, { 2, 1 } },
	{ { -1, -1 }, { -1, 0 }, { -1, 1 }, { 0, -1 }, { 0, 1 }, { 1, -1 }, { 1, 0 }, { 1, 1 } },
	{ { -1, -1 }, { 1, -1 }, { -1, 1 }, { 1, 1 } },
	{ { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } }
};

char board[ ROW ][ COLUMN ];

bool is_valid(int i, int j){
	return i >= 0 && i < ROW && j >= 0 && j < COLUMN;
}

bool pawn(int i, int j, int r, int c){
	return i - 1 == r && abs(j - c) == 1;
}

bool check_point(int i, int j, int r, int c, int d){
	for(int k = 0 ; k < dir[ d ].size() ; k++)
		if(i + dir[ d ][ k ].F == r && j + dir[ d ][ k ].S == c)
			return 1;
	return 0;
}

bool check_path(int i, int j, int r, int c, int d){
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

bool get(int r, int c){
	if(!board[ r ][ c ] >= 65 && board[ r ][ c ] <= 90)
		return 0;

	for(int i = 0 ; i < ROW ; i++){
		for(int j = 0 ; j < COLUMN ; j++){
			if(board[ i ][ j ] == 'p' && pawn(i, j, r, c))
				return 1;
			else if(board[ i ][ j ] == 'c' && check_point(i, j, r, c, 0))
				return 1;
			else if(board[ i ][ j ] == 't' && check_path(i, j, r, c, 3))
				return 1;
			else if(board[ i ][ j ] == 'b' && check_path(i, j, r, c, 2))
				return 1;
			else if(board[ i ][ j ] == 'r' && check_path(i, j, r, c, 1))
				return 1;
			else if(board[ i ][ j ] == 'k' && check_point(i, j, r, c, 1))
				return 1;
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
	cout << (get(r, c) ? "Sim" : "Nao") << endl;
	return 0;
}
// Problem name: MaratonIME plays Chess
// Problem link: https://vjudge.net/problem/Gym-100985D
// Submission link: https://vjudge.net/solution/16014227

#include <bits/stdc++.h>

#define ROW ((int)8)
#define COLUMN ((int)8)
#define endl '\n'

using namespace std;

char board[ ROW ][ COLUMN ];

int knight_x[ 8 ] = {-2, -2, -1, -1, 1, 1, 2, 2};
int knight_y[ 8 ] = {-1, 1, -2, 2, -2, 2, -1, 1};

int king_x[ 8 ] = {-1, -1, -1, 0, 0, 1, 1, 1};
int king_y[ 8 ] = {-1, 0, 1, -1, 1, -1, 0, 1};

int bishop_x[ 4 ] = {-1, 1, -1, 1};
int bishop_y[ 4 ] = {-1, -1, 1, 1};

int rook_x[ 4 ] = {-1, 1, 0, 0};
int rook_y[ 4 ] = {0, 0, -1, 1};

bool is_valid(int i, int j){
	return i >= 0 && i < ROW && j >= 0 && j < COLUMN;
}

bool pawn(int i, int j, int r, int c){
	return i - 1 == r && abs(j - c) == 1;
}

bool check_point(int x, int y, int r, int c, int *xl, int *yl, int n){
	for(int i = 0 ; i < n ; i++)
		if(r == x + xl[ i ] && c == y + yl[ i ])
			return 1;
	return 0;
}

bool check_path(int x, int y, int r, int c, int *xl, int *yl, int n){
	for(int i = 0 ; i < n ; i++){
		int a = x + xl[ i ];
		int b = y + yl[ i ];
		while(is_valid(a, b)){
			if(a < 0 || a >= 8 || b < 0 || b >= 8)
				break;

			if( a == r && b == c)
				return 1;

			if(board[ a ][ b ] != '.')
				break;

			a += xl[ i ];
			b += yl[ i ];
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
			else if(board[ i ][ j ] == 'c' && check_point(i, j, r, c, knight_x, knight_y, 8))
				return 1;
			else if(board[ i ][ j ] == 't' && check_path(i, j, r, c, rook_x, rook_y, 4))
				return 1;
			else if(board[ i ][ j ] == 'b' && check_path(i, j, r, c, bishop_x, bishop_y, 4))
				return 1;
			else if(board[ i ][ j ] == 'r' && check_path(i, j, r, c, king_x, king_y, 8))
				return 1;
			else if(board[ i ][ j ] == 'k' && check_point(i, j, r, c, king_x, king_y, 8))
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
	cout << (get(r, c) ?"Sim":"Nao") << endl;
	return 0;
}
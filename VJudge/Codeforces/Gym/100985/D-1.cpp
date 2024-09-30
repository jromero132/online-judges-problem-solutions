// Problem name: MaratonIME plays Chess
// Problem link: https://vjudge.net/problem/Gym-100985D
// Submission link: https://vjudge.net/solution/16014204

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

char s[ 10 ][ 10 ], ss[ 10 ];

int tx, ty;

int knight_x[ 8 ] = {-2, -2, -1, -1, 1, 1, 2, 2};
int knight_y[ 8 ] = {-1, 1, -2, 2, -2, 2, -1, 1};

int king_x[ 8 ] = {-1, -1, -1, 0, 0, 1, 1, 1};
int king_y[ 8 ] = {-1, 0, 1, -1, 1, -1, 0, 1};

int bishop_x[ 4 ] = {-1, 1, -1, 1};
int bishop_y[ 4 ] = {-1, -1, 1, 1};

int rook_x[ 4 ] = {-1, 1, 0, 0};
int rook_y[ 4 ] = {0, 0, -1, 1};

bool check_point(int x, int y, int *xl, int *yl, int n){
	for(int i = 0 ; i < n ; i++){
		int a = x + xl[ i ];
		int b = y + yl[ i ];
		if(tx == a && ty == b)
			return 1;
	}
	return 0;
}

bool check_path(int x, int y, int *xl, int *yl, int n){
	for(int i = 0 ; i < n ; i++){
		int a = x;
		int b = y;
		while(1){
			a += xl[ i ];
			b += yl[ i ];

			if(a < 0 || a >= 8 || b < 0 || b >= 8)
				break;

			if( a == tx && b == ty)
				return 1;

			if(s[ a ][ b ] != '.')
				break;
		}
	}
	return 0;
}

bool ok(){
	if(!s[ tx ][ ty ] >= 'A' && s[ tx ][ ty ] <= 'Z')
		return 0;

	for(int i = 0 ; i < 8 ; i++){
		for(int j = 0 ; j < 8 ; j++){
			if(s[i][j]=='p'){
				if(i==tx+1&&abs(j-ty)==1)
					return 1;
			}
			else if(s[i][j]=='c'){
				if(check_point(i, j, knight_x, knight_y, 8))
					return 1;
			}
			else if(s[i][j]=='t'){
				if(check_path(i, j, rook_x, rook_y, 4))
					return 1;
			}
			else if(s[i][j]=='b'){
				if(check_path(i, j, bishop_x, bishop_y, 4))
					return 1;
			}
			else if(s[i][j]=='r'){
				if(check_path(i, j, king_x, king_y, 8))
					return 1;
			}
			else if(s[i][j]=='k'){
				if(check_point(i, j, king_x, king_y, 8))
					return 1;
			}
		}
	}
	return 0;
}

int main(){

	while(~scanf("%s", s[ 0 ])){
		for(int i = 1 ; i < 8 ; i++)
			scanf("%s", s[ i ]);
		scanf("%s", ss);
		tx='8'-ss[1];
		ty=ss[0]-'a';
		puts(ok()?"Sim":"Nao");
	}
	return 0;
}
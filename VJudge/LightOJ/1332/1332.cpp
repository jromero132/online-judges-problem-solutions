// Problem name: Kings in Chessboard
// Problem link: https://vjudge.net/problem/LightOJ-1332
// Submission link: https://vjudge.net/solution/18102881

#include <bits/stdc++.h>

#define ROWS 10
#define F first
#define S second

using namespace std;

typedef unsigned int uint;
typedef pair<int, int> pii;
typedef vector<uint> vui;
typedef vector<vui> matrix;

matrix multiply(matrix &a, matrix &b){
	int n = a.size(), m = a[ 0 ].size(), o = b[ 0 ].size();
	matrix mat(n, vui(o, 0));
	for(int i = 0 ; i < n ; ++i)
		for(int k = 0 ; k < m ; ++k)
			for(int j = 0 ; j < o ; ++j)
				mat[ i ][ j ] += a[ i ][ k ] * b[ k ][ j ];
	return mat;
}

matrix pow(matrix m, int p){
	int len = m.size();
	matrix ans(len, vui(len, 0));
	for(int i = 0 ; i < len ; ans[ i ][ i ] = 1, ++i);
	for( ; p ; p >>= 1){
		if(p & 1)
			ans = multiply(ans, m);
		m = multiply(m, m);
	}
	return ans;
}

map<pii, int> id;

void preprocess(){
	for(int i = 1, p = 0 ; i <= ROWS ; ++i)
		for(int j = i + 2 ; j <= ROWS ; ++j)
			id[ pii(i, j) ] = p++;
}

matrix get_matrix(){
	matrix ans(id.size(), vui(id.size(), 0));
	for(int i = 1 ; i <= ROWS ; ++i){
		for(int j = i + 2 ; j <= ROWS ; ++j){
			for(int ii = 1 ; ii <= ROWS ; ++ii){
				if(abs(ii - i) >= 2 && abs(ii - j) >= 2){
					for(int jj = ii + 2 ; jj <= ROWS ; ++jj){
						if(abs(jj - i) >= 2 && abs(jj - j) >= 2){
							ans[ id[ pii(ii, jj) ] ][ id[ pii(i, j) ] ] = 1;
						}
					}
				}
			}
		}
	}
	return ans;
}

int main(){
#ifdef JoseA132
	freopen("01.in", "r", stdin);
#endif

	preprocess();
	matrix M = get_matrix();

	int t;
	scanf("%d", &t);
	for(int k = 1 ; k <= t ; ++k){
		int n;
		scanf("%d", &n);
		matrix M2 = pow(M, n - 1);
		uint ans = 0;
		for(int i = 0 ; i < M2.size() ; ++i)
			for(int j = 0 ; j < M2[ i ].size() ; ++j)
				ans += M2[ i ][ j ];
		printf("Case %d: %u\n", k, ans);
	}
	return 0;
}
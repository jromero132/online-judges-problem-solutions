// Problem name: Largest Rectangle
// Problem link: https://vjudge.net/problem/Aizu-DPL_3_B
// Submission link: https://vjudge.net/solution/12786001

#include <bits/stdc++.h>

#define MAX ((int)1410)
#define endl '\n'

using namespace std;

int n, m, matrix[ MAX ][ MAX ], width[ MAX ];

int maxArea(int r){
	stack<int> left, right;
	int ans = 0;
	for(int i = 0 ; i < m ; width[ i++ ] = 1);
	for(int i = 0 ; i < m ; i++){
		while(!left.empty() && matrix[ r ][ i ] <= matrix[ r ][ left.top() ])
			left.pop();
		if(left.empty())
			width[ i ] += i;
		else
			width[ i ] += i - left.top() - 1;
		left.push(i);
	}
	for(int i = m - 1 ; i >= 0 ; i--){
		while(!right.empty() && matrix[ r ][ i ] <= matrix[ r ][ right.top() ])
			right.pop();
		if(right.empty())
			width[ i ] += m - 1 - i;
		else
			width[ i ] += right.top() - i - 1;
		right.push(i);
	}
	for(int i = 0 ; i < m ; i++)
		ans = max(ans, width[ i ] * matrix[ r ][ i ]);
	return ans;
}

int maxArea(){
	int ans = maxArea(0);
	for(int i = 1 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++)
			matrix[ i ][ j ] = matrix[ i ][ j ] * (matrix[ i - 1 ][ j ] + matrix[ i ][ j ]);
		ans = max(ans, maxArea(i));
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < m ; j++)
			cin >> matrix[ i ][ j ], matrix[ i ][ j ] = (matrix[ i ][ j ] + 1) & 1;
	cout << maxArea() << endl;
	return 0;
}
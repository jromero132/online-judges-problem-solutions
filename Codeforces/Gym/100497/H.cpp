// Problem name: Pascal
// Problem link: https://codeforces.com/gym/100497/problem/H
// Submission link: https://codeforces.com/gym/100497/submission/21234506

#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<cstring>
#include<string>
#include<cmath>
#include<stack>
#include<queue>
#include<cstdlib>
#include<map>
#include <bits/stdc++.h>

using namespace std;

#define DB( x ) cout << #x << " = " << x << endl;
#define LEFT(n) (2 * (n))
#define RIGHT(n) (2 * (n) + 1)
#define X real()
#define Y imag()

typedef long long ll;
typedef pair<int, int> node;
//typedef complex<double> P;

const ll INF = 1e9;
const double EPS = 1e-6;
const ll MOD = (ll)(1e5);
const ll MAXV = (ll)(1e5 + 1000);
const ll MAXE = (ll)(1e6 + 10);



int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	int solve = 0;
	for(int i = 2 ; i * i <= n ; i++){
		if(n % i == 0)
		{
			solve = n/i;
			break;
		}
	}
	if(solve == 0)
		solve++;
	cout << n - solve << endl;

	return 0;
}
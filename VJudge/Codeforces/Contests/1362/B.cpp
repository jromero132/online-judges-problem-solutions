// Problem name: Johnny and His Hobbies
// Problem link: https://vjudge.net/problem/CodeForces-1362B
// Submission link: https://vjudge.net/solution/32998724

#include <bits/stdc++.h>

using namespace std;

int get_xor(int a, int b){
	int ans = 0;
	for(int mask = 1 ; mask <= a || mask <= b ; mask <<= 1)
		ans |= (a & mask) ^ (b & mask);
	return ans;
}

int solve(vector<int> &s){
	int ans = -1;
	vector<int> cur(s.size());
	for(int i = 1 ; i < s.size() ; ++i){
		int v = get_xor(s[ 0 ], s[ i ]);
		for(int j = 0 ; j < s.size() ; ++j)
			cur[ j ] = s[ j ] ^ v;
		sort(cur.begin(), cur.end());
		if(s == cur && (ans == -1 || v < ans))
			ans = v;
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;
	for(cin >> t ; t-- ; ){
		int n;
		cin >> n;
		vector<int> s(n);
		for(int &x : s)
			cin >> x;
		sort(s.begin(), s.end());
		cout << solve(s) << endl;
	}
	return 0;
}
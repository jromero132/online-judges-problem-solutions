// Problem name: Cave
// Problem link: https://codeforces.com/gym/100523/problem/J
// Submission link: https://codeforces.com/gym/100523/submission/35739089

#include <bits/stdc++.h>

#define ALL(v, it) for(auto it = v.begin() ; it != v.end() ; it++)
#define F first
#define S second

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	vector< vector<int> > son(N);
	for(int i = 1 ; i < N ; i++){
		int a;
		cin >> a;
		son[ --a ].push_back(i);
	}
	vector<int> S(N, 1);
	for(int i = N - 1 ; i >= 0 ; i--)
		ALL(son[ i ], it)
			S[ i ] += S[ *it ];
	vector< pair<int,int> > D;
	for(int i = 0 ; i < N ; i++)
		if(son[ i ].size() > 1)
			D.push_back(make_pair(son[ i ].size(), i));
	//sort(D.begin(), D.end());
	cout << 1;
	for(int k = N - 1 ; k >= 1 ; k--)
		if(N % k == 0){
			bool ok = true;
			for(int i = D.size() - 1 ; i >= 0 ; i--)
				if(S[ D[ i ].S ] > k){
					int s = 0;
					ALL(son[ D[ i ].S ], it)
						s += S[ *it ] % k;
					if(s + 1 > k){
						ok = false;
						break;
					}
				}
				if(ok)
					cout << " " << N / k;
		}
	cout << "\n";
	return 0;
}
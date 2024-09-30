// Problem name: Consecutive Subsequence
// Problem link: https://codeforces.com/contest/977/problem/F
// Submission link: https://codeforces.com/contest/977/submission/37967401

#include <bits/stdc++.h>

#define MAX ((int)200001)
#define pb push_back
#define F first
#define S second
#define endl '\n'

using namespace std;

typedef long long ll;

map<int, int> m;
map<int, int>::iterator it;
int s[ MAX ], parent[ MAX ];

void print(int v){
	if(parent[ v ] == -1){
		cout << v;
		return;
	}
	print(parent[ v ]);
	cout << ' ' << v;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, v, p;
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
    	cin >> v;
    	it = m.find(v -  1);
    	if(it != m.end()){
    		p = (it -> second);
    		s[ i ] = s[ p ] + 1;
    		parent[ i ] = p;
    		m[ v ] = i;
    	}
    	else{
    		it = m.find(v);
    		if(it == m.end()){
    			s[ i ] = 1;
    			parent[ i ] = -1;
    			m[ v ] = i;
    		}
    		else{
    			s[ 0 ] = 0;
    			parent[ i ] = -1;
    		}
    	}
    }
    v = 0;
    for(int i = 1 ; i <= n ; i++)
    	if(s[ i ] > v)
    		v = s[ i ], p = i;
    cout << v << endl;
    print(p);
    cout << endl;
    return 0;
}
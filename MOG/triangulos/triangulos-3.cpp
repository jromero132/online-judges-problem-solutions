// Problem name: C - Triángulos
// Problem link: https://matcomgrader.com/problem/4700/triangulos/
// Submission link: https://matcomgrader.com/submission/125427/

#include <bits/stdc++.h>

#define MAX ((int)1e6)
#define pb push_back
#define endl '\n'

using namespace std;

int main() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int n, a, b, c;
    vector<int> num;
    while(cin >> n && n)
    	num.pb(n);

    n = num.size() - 1;
    for(int i = 0 ; i < MAX ; i++){
    	a = uniform_int_distribution<int>(0, n)(rng);
    	do
    		b = uniform_int_distribution<int>(0, n)(rng);
    	while(b == a);
    	do
    		c = uniform_int_distribution<int>(0, n)(rng);
    	while(c == a || c == b);
    	a = num[ a ], b = num[ b ], c = num[ c ];
    	if(max(a, max(b, c)) < a + b - max(a, max(b, c)) + c){
    		cout << a << ' ' << b << ' ' << c << endl;
    		return 0;
    	}
    }
    cout << "NO" << endl;
    return 0;
}
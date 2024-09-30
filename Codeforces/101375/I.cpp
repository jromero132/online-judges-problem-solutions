// Problem name: MaratonIME divides fairly
// Problem link: https://codeforces.com/gym/101375/problem/I
// Submission link: https://codeforces.com/gym/101375/submission/37113181

#include <bits/stdc++.h>

#define MAX ((int)100000)
#define endl '\n'

using namespace std;

typedef long long ll;

int h[ MAX ];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    int t, a, b;
    for(cin >> t ; t-- ; ){
        cin >> a >> b;
        if(abs(a - b) <= 1)
            cout << "Ok" << endl;
        else
            cout << ((a + b) >> 1) << ' ' << ((a + b + 1) >> 1) << endl;
    }
	return 0;
}
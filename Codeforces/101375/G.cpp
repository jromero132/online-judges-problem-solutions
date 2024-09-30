// Problem name: MaratonIME does a competition
// Problem link: https://codeforces.com/gym/101375/problem/G
// Submission link: https://codeforces.com/gym/101375/submission/37113441

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int sum[ 4 ];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    int n, v, p = 0;
    cin >> n;
    for(int i = 0 ; i < n ; i++)
        cin >> v, sum[ i % 4 ] += v;
    for(int i = 1 ; i <= 3 ; i++)
        if(sum[ i ] > sum[ p ])
            p = i;
    cout << (char)(65 + p) << endl;
	return 0;
}
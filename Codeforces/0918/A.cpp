// Problem name: Eleven
// Problem link: https://codeforces.com/contest/918/problem/A
// Submission link: https://codeforces.com/contest/918/submission/34672846

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    string s(n, 'o');
    for(int a = 1, b = 1, c ; b <= n ; c = a, a = b, b += c)
    	s[ b - 1 ] = 'O';
	cout << s;
    return 0;
}
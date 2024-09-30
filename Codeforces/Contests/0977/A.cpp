// Problem name: Wrong Subtraction
// Problem link: https://codeforces.com/contest/977/problem/A
// Submission link: https://codeforces.com/contest/977/submission/37933521

#include <bits/stdc++.h>

#define push_back pb
#define endl '\n'

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    for(int i = 0 ; i < k ; i++)
    	if(n % 10)
    		n--;
    	else
    		n /= 10;
    cout << n << endl;
    return 0;
}
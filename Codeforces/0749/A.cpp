// Problem name: Bachgold Problem
// Problem link: https://codeforces.com/contest/749/problem/A
// Submission link: https://codeforces.com/contest/749/submission/23230665

#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    cout << n / 2 << endl;
    for(int i = 1 ; i < n / 2 ; i++)
	cout << "2 ";
    cout << (n & 1 ? 3 : 2); 
    return 0;
}
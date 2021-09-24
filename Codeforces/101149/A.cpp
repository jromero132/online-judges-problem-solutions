// Problem name: Balls in Urn
// Problem link: https://codeforces.com/gym/101149/problem/A
// Submission link: https://codeforces.com/gym/101149/submission/22168910

#include <iostream>

using namespace std;

int main(){
    int n, m = 0, a;
    cin >> n;
    for(int i = 0 ; i < n ; i++)
	cin >> a, m = (m < a ? a : m);
    cout << m << endl;
    return 0;
}
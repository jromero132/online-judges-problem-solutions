// Problem name: MaratonIME gets candies
// Problem link: https://codeforces.com/gym/101375/problem/H
// Submission link: https://codeforces.com/gym/101375/submission/37113685

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    int left = 1, right = 1000000000, middle;
    char c;
    while(left <= right){
        middle = left + ((right - left) >> 1);
        cout << "Q " << middle << endl;
        cout.flush();
        cin >> c;
        if(c == '=')
            break;
        if(c == '<')
            right = middle - 1;
        else
            left = middle + 1;
    }
    if(c != '=')
        cout << "Q " << right << endl, cout.flush();
	return 0;
}
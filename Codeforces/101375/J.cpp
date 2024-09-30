// Problem name: MaratonIME goes to Mito
// Problem link: https://codeforces.com/gym/101375/problem/J
// Submission link: https://codeforces.com/gym/101375/submission/37134487

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    int n, m, last, now;
    char c_last, c_now;
    cin >> n >> m >> last >> c_last;
    if(c_last == 'M'){
        cout << "No" << endl;
        return 0;
    }
    while(--m){
        cin >> now >> c_now;
        if((now - last <= 3 && c_last != c_now) || c_now == 'M'){
            cout << "No" << endl;
            return 0;
        }
        last = now;
        c_last = c_now;
    }
    cout << "Yes" << endl;
	return 0;
}
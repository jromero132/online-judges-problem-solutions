// Problem name: Radio Station
// Problem link: https://codeforces.com/contest/918/problem/B
// Submission link: https://codeforces.com/contest/918/submission/34670859

#include <bits/stdc++.h>

using namespace std;

map<string, string> name;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    string s1, s2;
    for(int i = 0 ; i < n ; i++)
    	cin >> s1 >> s2, name[ s2 ] = s1;
	while(m--)
		cin >> s1 >> s2, cout << s1 << ' ' << s2 << " #" << name[ s2.substr(0, s2.length() - 1) ] << endl;
    return 0;
}
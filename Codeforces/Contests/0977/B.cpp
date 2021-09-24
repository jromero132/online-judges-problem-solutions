// Problem name: Two-gram
// Problem link: https://codeforces.com/contest/977/problem/B
// Submission link: https://codeforces.com/contest/977/submission/37942574

#include <bits/stdc++.h>

#define MAX ((int)101)
#define endl '\n'

using namespace std;

typedef long long ll;

map<string, int> m;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, now = 0;
    string s, s1;
    cin >> n >> s;
    for(int i = 1 ; i < n ; i++)
    	s1 = s[ i - 1 ], s1 += s[ i ], m[ s1 ]++;
    for(auto it : m){
    	if((it.second) > now)
    		now = (it.second), s1 = (it.first);
    }
    cout << s1 << endl;
    return 0;
}
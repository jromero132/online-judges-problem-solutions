// Problem name: Do Not Be Distracted!
// Problem link: https://codeforces.com/contest/1520/problem/A
// Submission link: https://codeforces.com/contest/1520/submission/121068151

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool distracted(string s){
    for(int i = 0 ; i < s.length() ; ++i){
        bool changed = 0;
        for(int j = i + 1 ; j < s.length() ; ++j){
            if(s[ i ] != s[ j ])
                changed = 1;
            else if(changed)
                return 1;
        }
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    for(cin >> t ; t-- ; ){
        int n;
        string s;
        cin >> n >> s;
        cout << (!distracted(s) ? "YES" : "NO") << endl;
    }
    return 0;
}
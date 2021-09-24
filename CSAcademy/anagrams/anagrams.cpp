// Problem name: Anagrams
// Problem link: https://csacademy.com/contest/archive/task/anagrams/
// Submission link: https://csacademy.com/submission/1407486/

#include <bits/stdc++.h>

#define MAX ((int)100000)
#define MOD ((int)1000000007)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define endl '\n'

using namespace std;

string word[ MAX ];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, ans = 0, now;
    string s;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> s;
        sort(s.begin(), s.end());
        word[ i ] = s;
    }
    sort(word, word + n);
    now = 1;
    for(int i = 0 ; i < n ; i++){
        if(word[ i ] == word[ i - 1 ])
            now++;
        else{
            ans = max(ans, now);
            now = 1;
        }
    }
    cout << max(ans, now) << endl;
    return 0;
}
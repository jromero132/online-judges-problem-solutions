// Problem name: Make a Square
// Problem link: https://codeforces.com/contest/962/problem/C
// Submission link: https://codeforces.com/contest/962/submission/37159478

#include <bits/stdc++.h>

#define MAX ((int)2000000000)
#define INF ((int)100)
#define endl '\n'

using namespace std;

set<int> square;

void preprocess(){
    for(int i = 1 ; i * i <= MAX ; i++)
        square.insert(i * i);
}

bool f(string s){
    int num = 0;
    for(int i = 0 ; s[ i ] ; i++)
        if(s[ i ] != '.')
            num *= 10, num += s[ i ] - 48;
    return square.find(num) != square.end();
}

int solve(string s, int m){
    int p;
    for(p = 0 ; s[ p ] == '.' ; p++);
    if(s[ p ] == '\0' || s[ p ] == '0')
        return INF;
    if(f(s))
        return m;
    int ans = INF;
    for(int i = p ; s[ i ] ; i++){
        if(s[ i ] != '.'){
            char c = s[ i ];
            s[ i ] = '.';
            ans = min(ans, solve(s, m + 1));
            s[ i ] = c;
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    preprocess();

    string s;
    cin >> s;
    int ans = solve(s, 0);
    cout << (ans == INF ? -1 : ans) << endl;
    return 0;
}
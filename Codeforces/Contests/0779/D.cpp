// Problem name: String Game
// Problem link: https://codeforces.com/contest/779/problem/D
// Submission link: https://codeforces.com/contest/779/submission/25064606

#include <iostream>

#define MAX (int)(2e5 + 3)

using namespace std;

string s, ss;
int permutation[ MAX ];

bool valid(string now){
    int p = 0;
    for(int i = 0 ; now[ i ] != '\0' && ss[ p ] != '\0' ; i++)
        if(now[ i ] == ss[ p ])
            p++;
    return ss[ p ] == '\0';
}

bool check(int n){
    string res = s, now = "";
    for(int i = 0 ; i < n ; res[ permutation[ i++ ] - 1 ] = 32);
    for(int i = 0 ; res[ i ] != '\0' ; i++)
        if(res[ i ] != 32)
            now += res[ i ];
    return valid(now);
}

int solve(){
    int left = 0, right = s.length() - 1, mid;
    while(left <= right){
        mid = (left + right) / 2;
        if(check(mid))
            left = mid + 1;
        else
            right = mid - 1;
    }
    return right;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s >> ss;
    for(int i = 0 ; s[ i ] != '\0' ; i++)
        cin >> permutation[ i ];
    cout << solve();
    return 0;
}
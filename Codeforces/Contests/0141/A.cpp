// Problem name: Amusing Joke
// Problem link: https://codeforces.com/contest/141/problem/A
// Submission link: https://codeforces.com/contest/141/submission/25200896

#include <bits/stdc++.h>

#define MAX (int)(3e1 + 3)

using namespace std;

int letter[ MAX ];

bool check(){
    for(int i = 0 ; i < MAX ; i++)
        if(letter[ i ])
            return 0;
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    for(int i = 0 ; s1[ i ] != '\0' ; letter[ s1[ i++ ] - 65 ]++);
    for(int i = 0 ; s2[ i ] != '\0' ; letter[ s2[ i++ ] - 65 ]++);
    for(int i = 0 ; s3[ i ] != '\0' ; letter[ s3[ i++ ] - 65 ]--);
    cout << (check() ? "YES" : "NO");
    return 0;
}
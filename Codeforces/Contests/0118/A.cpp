// Problem name: String Task
// Problem link: https://codeforces.com/contest/118/problem/A
// Submission link: https://codeforces.com/contest/118/submission/20929739

#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    string s;
    cin >> s;
    for(int i = 0 ; s[ i ] != '\0' ; i++){
        s[ i ] = tolower(s[ i ]);
        if(s[ i ] == 'a' || s[ i ] == 'e' || s[ i ] == 'i' || s[ i ] == 'o' || s[ i ] == 'u' || s[ i ] == 'y')
            continue;
        else
            cout << "." << s [ i ];
    }
    return 0;
}
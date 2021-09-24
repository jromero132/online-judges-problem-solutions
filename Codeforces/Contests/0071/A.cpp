// Problem name: Way Too Long Words
// Problem link: https://codeforces.com/contest/71/problem/A
// Submission link: https://codeforces.com/contest/71/submission/20929683

#include <iostream>

#define endl '\n'

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    string s;
    for(cin >> n ; n ; n--){
        cin >> s;
        if(s.length() <= 10)
            cout << s << endl;
        else
            cout << s[ 0 ] << s.length() - 2 << s[ s.length() - 1 ] << endl;
    }
    return 0;
}
// Problem name: Watermelon
// Problem link: https://codeforces.com/contest/4/problem/A
// Submission link: https://codeforces.com/contest/4/submission/20929645

#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    cout << (!(n % 2) && n > 2 ? "YES" : "NO") << endl;
    return 0;
}
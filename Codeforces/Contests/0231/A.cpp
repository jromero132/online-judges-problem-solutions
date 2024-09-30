// Problem name: Team
// Problem link: https://codeforces.com/contest/231/problem/A
// Submission link: https://codeforces.com/contest/231/submission/20929773

#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, ans = 0, a, b, c;
    for(cin >> n ; n ; n--){
        cin >> a >> b >> c;
        ans += (a + b + c < 2 ? 0 : 1);
    }
    cout << ans << endl;
    return 0;
}
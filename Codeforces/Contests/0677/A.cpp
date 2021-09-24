// Problem name: Vanya and Fence
// Problem link: https://codeforces.com/contest/677/problem/A
// Submission link: https://codeforces.com/contest/677/submission/25081578

#include <iostream>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, h, x, ans = 0;
    cin >> n >> h;
    for(int i = 0 ; i < n ; i++)
        cin >> x, ans += (x <= h ? 1 : 2);
    cout << ans;
    return 0;
}
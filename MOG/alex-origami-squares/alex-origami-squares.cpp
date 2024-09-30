// Problem name: A - Alex Origami Squares
// Problem link: https://matcomgrader.com/problem/9267/alex-origami-squares/
// Submission link: https://matcomgrader.com/submission/119950/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    double a, b, ans = 0;
    cin >> a >> b;
    ans = min(a / 3, b);
    ans = max(ans, min(b / 3, a));
    ans = max(ans, min(a / 2, b / 2));
    cout << ans;
}
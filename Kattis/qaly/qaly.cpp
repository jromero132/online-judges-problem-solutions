// Problem name: Quality-Adjusted Life-Year
// Problem link: https://open.kattis.com/problems/qaly
// Submission link: https://open.kattis.com/submissions/3695685

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    
    int n;
    double ans = 0, x, y;
    for(cin >> n ; n-- ; )
        cin >> x >> y, ans += x * y;
    cout << setprecision(5) << fixed << ans << endl;
    return 0;
}
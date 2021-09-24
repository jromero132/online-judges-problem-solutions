// Problem name: Tarifa
// Problem link: https://open.kattis.com/problems/tarifa
// Submission link: https://open.kattis.com/submissions/3695657

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    
    int x, n, ans = 0, m;
    cin >> x >> n;
    while(n--)
        cin >> m, ans += x - m;
    cout << ans + x << endl;
    return 0;
}
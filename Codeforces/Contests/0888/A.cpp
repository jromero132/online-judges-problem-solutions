// Problem name: Local Extrema
// Problem link: https://codeforces.com/contest/888/problem/A
// Submission link: https://codeforces.com/contest/888/submission/37915695

#include <bits/stdc++.h>


#define endl '\n'

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, ans = 0;
    cin >> n;
    vector<int> num(n--);
    for(auto &v : num)
    	cin >> v;
    for(int i = 1 ; i < n ; i++)
    	ans += ((num[ i ] < num[ i - 1 ] && num[ i ] < num[ i + 1 ]) || (num[ i ] > num[ i - 1 ] && num[ i ] > num[ i + 1 ]));
    cout << ans << endl;
    return 0;
}
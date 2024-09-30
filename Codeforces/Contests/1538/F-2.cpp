// Problem name: Interesting Function
// Problem link: https://codeforces.com/contest/1538/problem/F
// Submission link: https://codeforces.com/contest/1538/submission/121061329

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll digit_changes(int n){
    ll ans = 0;
    while(n)
        ans += n, n /= 10;
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    for(cin >> t ; t-- ; ){
        int a, b;
        cin >> a >> b;
        cout << digit_changes(b) - digit_changes(a) << endl;
    }
    return 0;
}
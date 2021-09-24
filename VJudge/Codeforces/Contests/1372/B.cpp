// Problem name: Omkar and Last Class of Math
// Problem link: https://vjudge.net/problem/CodeForces-1372B
// Submission link: https://vjudge.net/solution/31795850

#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    if(!(n & 1)){
        cout << (n >> 1) << ' ' << (n >> 1) << endl;
        return;
    }
    int p = 1;
    for(int i = 3 ; i * i <= n ; i += 2){
        if(n % i == 0){
            p = n / i;
            break;
        }
    }
    cout << p << ' ' << n - p << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    for(cin >> t ; t-- ; solve());
    return 0;
}
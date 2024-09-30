// Problem name: Levko and Permutation
// Problem link: https://vjudge.net/problem/CodeForces-361B
// Submission link: https://vjudge.net/solution/31795858

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, k;
    cin >> n >> k;
    if(n == k){
        cout << -1 << endl;
    }
    else{
        cout << n - k;
        for(int i = 1 ; i < n - k ; ++i)
            cout << ' ' << i;
        for(int i = n - k + 1 ; i <= n ; ++i)
            cout << ' ' << i;
    }
    return 0;
}
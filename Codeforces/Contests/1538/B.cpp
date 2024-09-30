// Problem name: Friends and Candies
// Problem link: https://codeforces.com/contest/1538/problem/B
// Submission link: https://codeforces.com/contest/1538/submission/121044309

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    for(cin >> t ; t-- ; ){
        int n, sum = 0;
        cin >> n;
        int v[ n ];
        for(int i = 0 ; i < n ; ++i){
            cin >> v[ i ];
            sum += v[ i ];
        }
        if(sum % n)
            cout << -1 << endl;
        else{
            int k = 0;
            sum /= n;
            for(int i = 0 ; i < n ; k += v[ i++ ] > sum);
            cout << k << endl;
        }
    }
    return 0;
}
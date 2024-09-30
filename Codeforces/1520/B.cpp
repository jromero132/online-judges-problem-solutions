// Problem name: Ordinary Numbers
// Problem link: https://codeforces.com/contest/1520/problem/B
// Submission link: https://codeforces.com/contest/1520/submission/121068381

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int num_ordinary(int n){
    int ans = 0;
    for(int c = 1 ; c <= 10 ; ++c){
        for(int d = 1 ; d <= 9 ; ++d){
            int cur = 0;
            for(int i = 0 ; i < c ; ++i)
                cur *= 10, cur += d;
            if(cur > n)
                break;
            ++ans;
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    for(cin >> t ; t-- ; ){
        int n;
        cin >> n;
        cout << num_ordinary(n) << endl;
    }
    return 0;
}
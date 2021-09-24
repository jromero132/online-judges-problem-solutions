// Problem name: Not Adjacent Matrix
// Problem link: https://codeforces.com/contest/1520/problem/C
// Submission link: https://codeforces.com/contest/1520/submission/121068813

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

void construct(int n){
    if(n == 2){
        cout << -1 << endl;
        return;
    }
    vvi matrix(n, vi(n));
    int i = 0, j = 0;
    for(int c = 1, l = n * n ; c <= l ; ++c){
        matrix[ i ][ j ] = c;
        j += 2;
        if(j >= n)
            ++i, j -= n;
        if(i == n)
            i = 0, j = 1;
    }
    for(int i = 0 ; i < n ; ++i){
        for(int j = 0 ; j < n ; ++j)
            cout << (j ? " " : "") << matrix[ i ][ j ];
        cout << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    for(cin >> t ; t-- ; ){
        int n;
        cin >> n;
        construct(n);
    }
    return 0;
}